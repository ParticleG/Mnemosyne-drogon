//
// Created by particleg on 2021/9/27.
//

#include <filters/AuthLoginEmail.h>
#include <helpers/RequestJson.h>
#include <structures/Exceptions.h>

using namespace drogon;
using namespace std;
using namespace mnemosyne::filters;
using namespace mnemosyne::helpers;
using namespace mnemosyne::structures;
using namespace mnemosyne::types;

void AuthLoginEmail::doFilter(
        const HttpRequestPtr &req,
        FilterCallback &&failedCb,
        FilterChainCallback &&nextCb
) {
    handleExceptions([&]() {
        auto request = RequestJson(req);
        request.require("email", JsonValue::String);
        if (!(
                request.check("code", JsonValue::String) ||
                request.check("password", JsonValue::String)
        )) {
            throw json_exception::WrongType(JsonValue::String);
        }
        req->attributes()->insert("requestJson", request);
        nextCb();
    }, failedCb);
}
