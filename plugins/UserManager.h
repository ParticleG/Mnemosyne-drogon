//
// Created by Parti on 2021/2/4.
//

#pragma once

#include <drogon/plugins/Plugin.h>
#include <helpers/EmailHelper.h>
#include <helpers/I18nHelper.h>
#include <helpers/RequestJson.h>
#include <models/Users.h>
#include <structures/UserRedis.h>

namespace mnemosyne::plugins {
    class UserManager :
            public drogon::Plugin<UserManager>,
            public helpers::I18nHelper<UserManager> {
    public:
        static constexpr char projectName[] = CMAKE_PROJECT_NAME;

    public:
        void initAndStart(const Json::Value &config) override;

        void shutdown() override;

        [[nodiscard]] int64_t getUserId(const std::string &accessToken);

        structures::RedisToken refresh(const std::string &refreshToken);

        void verifyEmail(const std::string &email);

        [[nodiscard]] std::tuple<structures::RedisToken, bool> loginEmailCode(
                const std::string &email,
                const std::string &code
        );

        [[nodiscard]] structures::RedisToken loginEmailPassword(
                const std::string &email,
                const std::string &password
        );

        void resetEmail(
                const std::string &email,
                const std::string &code,
                const std::string &newPassword
        );

        void migrateEmail(
                const std::string &accessToken,
                const std::string &newEmail,
                const std::string &code
        );

        void deactivateEmail(
                const std::string &accessToken,
                const std::string &code
        );

        [[nodiscard]] Json::Value getUserInfo(
                const std::string &accessToken,
                const int64_t &userId
        );

        void updateUserInfo(
                const std::string &accessToken,
                helpers::RequestJson request
        );

        [[nodiscard]] std::string getAvatar(
                const std::string &accessToken,
                const int64_t &userId
        );

        [[nodiscard]] bool ipLimit(const std::string &ip) const;

        [[nodiscard]] bool emailLimit(const std::string &email) const;

    private:
        std::chrono::seconds _ipInterval{}, _emailInterval{};
        uint64_t _ipMaxCount{}, _emailMaxCount{};

        std::unique_ptr<helpers::EmailHelper> _emailHelper;
        std::unique_ptr<mnemosyne::structures::UserRedis> _userRedis;
        std::unique_ptr<drogon::orm::Mapper<drogon_model::Mnemosyne::Users>> _usersMapper;

        void _checkEmailCode(
                const std::string &email,
                const std::string &code
        );
    };
}

