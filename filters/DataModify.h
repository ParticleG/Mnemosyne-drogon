//
// Created by particleg on 2021/9/27.
//

#pragma once

#include <drogon/HttpFilter.h>
#include <structures/ExceptionHandlers.h>

/**
 * @brief This filter checks "Data::modify" request body
 * @param id: Int64
 * @param name: String
 * @param tags: String
 * @param collection: Int64
 * @param content: String
 * @return requestJson: in request attributes
 */
namespace mnemosyne::filters {
    class DataModify :
            public drogon::HttpFilter<DataModify>,
            public structures::RequestJsonHandler<DataModify> {
    public:
        static constexpr char projectName[] = CMAKE_PROJECT_NAME;

    public:
        void doFilter(
                const drogon::HttpRequestPtr &req,
                drogon::FilterCallback &&failedCb,
                drogon::FilterChainCallback &&nextCb
        ) override;
    };
}