/**
 *
 *  Collection.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Collection.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::Mnemosyne;

const std::string Collection::Cols::_id = "id";
const std::string Collection::Cols::_name = "name";
const std::string Collection::Cols::_description = "description";
const std::string Collection::Cols::_tags = "tags";
const std::string Collection::Cols::_content = "content";
const std::string Collection::Cols::_extra = "extra";
const std::string Collection::Cols::_created = "created";
const std::string Collection::primaryKeyName = "id";
const bool Collection::hasPrimaryKey = true;
const std::string Collection::tableName = "collection";

const std::vector<typename Collection::MetaData> Collection::metaData_={
{"id","int64_t","bigint",8,1,1,1},
{"name","std::string","text",0,0,0,1},
{"description","std::string","text",0,0,0,0},
{"tags","std::string","ARRAY",0,0,0,1},
{"content","std::string","ARRAY",0,0,0,1},
{"extra","std::string","text",0,0,0,0},
{"created","::trantor::Date","timestamp without time zone",0,0,0,1}
};
const std::string &Collection::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Collection::Collection(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            id_=std::make_shared<int64_t>(r["id"].as<int64_t>());
        }
        if(!r["name"].isNull())
        {
            name_=std::make_shared<std::string>(r["name"].as<std::string>());
        }
        if(!r["description"].isNull())
        {
            description_=std::make_shared<std::string>(r["description"].as<std::string>());
        }
        if(!r["tags"].isNull())
        {
            tags_=std::make_shared<std::string>(r["tags"].as<std::string>());
        }
        if(!r["content"].isNull())
        {
            content_=std::make_shared<std::string>(r["content"].as<std::string>());
        }
        if(!r["extra"].isNull())
        {
            extra_=std::make_shared<std::string>(r["extra"].as<std::string>());
        }
        if(!r["created"].isNull())
        {
            auto timeStr = r["created"].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                created_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 7 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            id_=std::make_shared<int64_t>(r[index].as<int64_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            name_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            description_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            tags_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 4;
        if(!r[index].isNull())
        {
            content_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 5;
        if(!r[index].isNull())
        {
            extra_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 6;
        if(!r[index].isNull())
        {
            auto timeStr = r[index].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                created_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }

}

Collection::Collection(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 7)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int64_t>((int64_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            name_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            description_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            tags_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            content_=std::make_shared<std::string>(pJson[pMasqueradingVector[4]].asString());
        }
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        dirtyFlag_[5] = true;
        if(!pJson[pMasqueradingVector[5]].isNull())
        {
            extra_=std::make_shared<std::string>(pJson[pMasqueradingVector[5]].asString());
        }
    }
    if(!pMasqueradingVector[6].empty() && pJson.isMember(pMasqueradingVector[6]))
    {
        dirtyFlag_[6] = true;
        if(!pJson[pMasqueradingVector[6]].isNull())
        {
            auto timeStr = pJson[pMasqueradingVector[6]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                created_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
}

Collection::Collection(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int64_t>((int64_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("name"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["name"].isNull())
        {
            name_=std::make_shared<std::string>(pJson["name"].asString());
        }
    }
    if(pJson.isMember("description"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["description"].isNull())
        {
            description_=std::make_shared<std::string>(pJson["description"].asString());
        }
    }
    if(pJson.isMember("tags"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["tags"].isNull())
        {
            tags_=std::make_shared<std::string>(pJson["tags"].asString());
        }
    }
    if(pJson.isMember("content"))
    {
        dirtyFlag_[4]=true;
        if(!pJson["content"].isNull())
        {
            content_=std::make_shared<std::string>(pJson["content"].asString());
        }
    }
    if(pJson.isMember("extra"))
    {
        dirtyFlag_[5]=true;
        if(!pJson["extra"].isNull())
        {
            extra_=std::make_shared<std::string>(pJson["extra"].asString());
        }
    }
    if(pJson.isMember("created"))
    {
        dirtyFlag_[6]=true;
        if(!pJson["created"].isNull())
        {
            auto timeStr = pJson["created"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                created_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
}

void Collection::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 7)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int64_t>((int64_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            name_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            description_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            tags_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            content_=std::make_shared<std::string>(pJson[pMasqueradingVector[4]].asString());
        }
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        dirtyFlag_[5] = true;
        if(!pJson[pMasqueradingVector[5]].isNull())
        {
            extra_=std::make_shared<std::string>(pJson[pMasqueradingVector[5]].asString());
        }
    }
    if(!pMasqueradingVector[6].empty() && pJson.isMember(pMasqueradingVector[6]))
    {
        dirtyFlag_[6] = true;
        if(!pJson[pMasqueradingVector[6]].isNull())
        {
            auto timeStr = pJson[pMasqueradingVector[6]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                created_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
}

void Collection::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int64_t>((int64_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("name"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["name"].isNull())
        {
            name_=std::make_shared<std::string>(pJson["name"].asString());
        }
    }
    if(pJson.isMember("description"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["description"].isNull())
        {
            description_=std::make_shared<std::string>(pJson["description"].asString());
        }
    }
    if(pJson.isMember("tags"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["tags"].isNull())
        {
            tags_=std::make_shared<std::string>(pJson["tags"].asString());
        }
    }
    if(pJson.isMember("content"))
    {
        dirtyFlag_[4] = true;
        if(!pJson["content"].isNull())
        {
            content_=std::make_shared<std::string>(pJson["content"].asString());
        }
    }
    if(pJson.isMember("extra"))
    {
        dirtyFlag_[5] = true;
        if(!pJson["extra"].isNull())
        {
            extra_=std::make_shared<std::string>(pJson["extra"].asString());
        }
    }
    if(pJson.isMember("created"))
    {
        dirtyFlag_[6] = true;
        if(!pJson["created"].isNull())
        {
            auto timeStr = pJson["created"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                created_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
}

const int64_t &Collection::getValueOfId() const noexcept
{
    const static int64_t defaultValue = int64_t();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<int64_t> &Collection::getId() const noexcept
{
    return id_;
}
void Collection::setId(const int64_t &pId) noexcept
{
    id_ = std::make_shared<int64_t>(pId);
    dirtyFlag_[0] = true;
}
const typename Collection::PrimaryKeyType & Collection::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &Collection::getValueOfName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(name_)
        return *name_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Collection::getName() const noexcept
{
    return name_;
}
void Collection::setName(const std::string &pName) noexcept
{
    name_ = std::make_shared<std::string>(pName);
    dirtyFlag_[1] = true;
}
void Collection::setName(std::string &&pName) noexcept
{
    name_ = std::make_shared<std::string>(std::move(pName));
    dirtyFlag_[1] = true;
}

const std::string &Collection::getValueOfDescription() const noexcept
{
    const static std::string defaultValue = std::string();
    if(description_)
        return *description_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Collection::getDescription() const noexcept
{
    return description_;
}
void Collection::setDescription(const std::string &pDescription) noexcept
{
    description_ = std::make_shared<std::string>(pDescription);
    dirtyFlag_[2] = true;
}
void Collection::setDescription(std::string &&pDescription) noexcept
{
    description_ = std::make_shared<std::string>(std::move(pDescription));
    dirtyFlag_[2] = true;
}
void Collection::setDescriptionToNull() noexcept
{
    description_.reset();
    dirtyFlag_[2] = true;
}

const std::string &Collection::getValueOfTags() const noexcept
{
    const static std::string defaultValue = std::string();
    if(tags_)
        return *tags_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Collection::getTags() const noexcept
{
    return tags_;
}
void Collection::setTags(const std::string &pTags) noexcept
{
    tags_ = std::make_shared<std::string>(pTags);
    dirtyFlag_[3] = true;
}
void Collection::setTags(std::string &&pTags) noexcept
{
    tags_ = std::make_shared<std::string>(std::move(pTags));
    dirtyFlag_[3] = true;
}

const std::string &Collection::getValueOfContent() const noexcept
{
    const static std::string defaultValue = std::string();
    if(content_)
        return *content_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Collection::getContent() const noexcept
{
    return content_;
}
void Collection::setContent(const std::string &pContent) noexcept
{
    content_ = std::make_shared<std::string>(pContent);
    dirtyFlag_[4] = true;
}
void Collection::setContent(std::string &&pContent) noexcept
{
    content_ = std::make_shared<std::string>(std::move(pContent));
    dirtyFlag_[4] = true;
}

const std::string &Collection::getValueOfExtra() const noexcept
{
    const static std::string defaultValue = std::string();
    if(extra_)
        return *extra_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Collection::getExtra() const noexcept
{
    return extra_;
}
void Collection::setExtra(const std::string &pExtra) noexcept
{
    extra_ = std::make_shared<std::string>(pExtra);
    dirtyFlag_[5] = true;
}
void Collection::setExtra(std::string &&pExtra) noexcept
{
    extra_ = std::make_shared<std::string>(std::move(pExtra));
    dirtyFlag_[5] = true;
}
void Collection::setExtraToNull() noexcept
{
    extra_.reset();
    dirtyFlag_[5] = true;
}

const ::trantor::Date &Collection::getValueOfCreated() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(created_)
        return *created_;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &Collection::getCreated() const noexcept
{
    return created_;
}
void Collection::setCreated(const ::trantor::Date &pCreated) noexcept
{
    created_ = std::make_shared<::trantor::Date>(pCreated);
    dirtyFlag_[6] = true;
}

void Collection::updateId(const uint64_t id)
{
}

const std::vector<std::string> &Collection::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "name",
        "description",
        "tags",
        "content",
        "extra",
        "created"
    };
    return inCols;
}

void Collection::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getName())
        {
            binder << getValueOfName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getDescription())
        {
            binder << getValueOfDescription();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getTags())
        {
            binder << getValueOfTags();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getContent())
        {
            binder << getValueOfContent();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[5])
    {
        if(getExtra())
        {
            binder << getValueOfExtra();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[6])
    {
        if(getCreated())
        {
            binder << getValueOfCreated();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Collection::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    if(dirtyFlag_[2])
    {
        ret.push_back(getColumnName(2));
    }
    if(dirtyFlag_[3])
    {
        ret.push_back(getColumnName(3));
    }
    if(dirtyFlag_[4])
    {
        ret.push_back(getColumnName(4));
    }
    if(dirtyFlag_[5])
    {
        ret.push_back(getColumnName(5));
    }
    if(dirtyFlag_[6])
    {
        ret.push_back(getColumnName(6));
    }
    return ret;
}

void Collection::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getName())
        {
            binder << getValueOfName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getDescription())
        {
            binder << getValueOfDescription();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getTags())
        {
            binder << getValueOfTags();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getContent())
        {
            binder << getValueOfContent();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[5])
    {
        if(getExtra())
        {
            binder << getValueOfExtra();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[6])
    {
        if(getCreated())
        {
            binder << getValueOfCreated();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Collection::toJson() const
{
    Json::Value ret;
    if(getId())
    {
        ret["id"]=(Json::Int64)getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getName())
    {
        ret["name"]=getValueOfName();
    }
    else
    {
        ret["name"]=Json::Value();
    }
    if(getDescription())
    {
        ret["description"]=getValueOfDescription();
    }
    else
    {
        ret["description"]=Json::Value();
    }
    if(getTags())
    {
        ret["tags"]=getValueOfTags();
    }
    else
    {
        ret["tags"]=Json::Value();
    }
    if(getContent())
    {
        ret["content"]=getValueOfContent();
    }
    else
    {
        ret["content"]=Json::Value();
    }
    if(getExtra())
    {
        ret["extra"]=getValueOfExtra();
    }
    else
    {
        ret["extra"]=Json::Value();
    }
    if(getCreated())
    {
        ret["created"]=getCreated()->toDbStringLocal();
    }
    else
    {
        ret["created"]=Json::Value();
    }
    return ret;
}

Json::Value Collection::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 7)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getId())
            {
                ret[pMasqueradingVector[0]]=(Json::Int64)getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getName())
            {
                ret[pMasqueradingVector[1]]=getValueOfName();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getDescription())
            {
                ret[pMasqueradingVector[2]]=getValueOfDescription();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getTags())
            {
                ret[pMasqueradingVector[3]]=getValueOfTags();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[4].empty())
        {
            if(getContent())
            {
                ret[pMasqueradingVector[4]]=getValueOfContent();
            }
            else
            {
                ret[pMasqueradingVector[4]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[5].empty())
        {
            if(getExtra())
            {
                ret[pMasqueradingVector[5]]=getValueOfExtra();
            }
            else
            {
                ret[pMasqueradingVector[5]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[6].empty())
        {
            if(getCreated())
            {
                ret[pMasqueradingVector[6]]=getCreated()->toDbStringLocal();
            }
            else
            {
                ret[pMasqueradingVector[6]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getId())
    {
        ret["id"]=(Json::Int64)getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getName())
    {
        ret["name"]=getValueOfName();
    }
    else
    {
        ret["name"]=Json::Value();
    }
    if(getDescription())
    {
        ret["description"]=getValueOfDescription();
    }
    else
    {
        ret["description"]=Json::Value();
    }
    if(getTags())
    {
        ret["tags"]=getValueOfTags();
    }
    else
    {
        ret["tags"]=Json::Value();
    }
    if(getContent())
    {
        ret["content"]=getValueOfContent();
    }
    else
    {
        ret["content"]=Json::Value();
    }
    if(getExtra())
    {
        ret["extra"]=getValueOfExtra();
    }
    else
    {
        ret["extra"]=Json::Value();
    }
    if(getCreated())
    {
        ret["created"]=getCreated()->toDbStringLocal();
    }
    else
    {
        ret["created"]=Json::Value();
    }
    return ret;
}

bool Collection::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if(pJson.isMember("name"))
    {
        if(!validJsonOfField(1, "name", pJson["name"], err, true))
            return false;
    }
    if(pJson.isMember("description"))
    {
        if(!validJsonOfField(2, "description", pJson["description"], err, true))
            return false;
    }
    if(pJson.isMember("tags"))
    {
        if(!validJsonOfField(3, "tags", pJson["tags"], err, true))
            return false;
    }
    if(pJson.isMember("content"))
    {
        if(!validJsonOfField(4, "content", pJson["content"], err, true))
            return false;
    }
    if(pJson.isMember("extra"))
    {
        if(!validJsonOfField(5, "extra", pJson["extra"], err, true))
            return false;
    }
    if(pJson.isMember("created"))
    {
        if(!validJsonOfField(6, "created", pJson["created"], err, true))
            return false;
    }
    return true;
}
bool Collection::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                    const std::vector<std::string> &pMasqueradingVector,
                                                    std::string &err)
{
    if(pMasqueradingVector.size() != 7)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty())
      {
          if(pJson.isMember(pMasqueradingVector[0]))
          {
              if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[1].empty())
      {
          if(pJson.isMember(pMasqueradingVector[1]))
          {
              if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[2].empty())
      {
          if(pJson.isMember(pMasqueradingVector[2]))
          {
              if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[3].empty())
      {
          if(pJson.isMember(pMasqueradingVector[3]))
          {
              if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[4].empty())
      {
          if(pJson.isMember(pMasqueradingVector[4]))
          {
              if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[5].empty())
      {
          if(pJson.isMember(pMasqueradingVector[5]))
          {
              if(!validJsonOfField(5, pMasqueradingVector[5], pJson[pMasqueradingVector[5]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[6].empty())
      {
          if(pJson.isMember(pMasqueradingVector[6]))
          {
              if(!validJsonOfField(6, pMasqueradingVector[6], pJson[pMasqueradingVector[6]], err, true))
                  return false;
          }
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Collection::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("name"))
    {
        if(!validJsonOfField(1, "name", pJson["name"], err, false))
            return false;
    }
    if(pJson.isMember("description"))
    {
        if(!validJsonOfField(2, "description", pJson["description"], err, false))
            return false;
    }
    if(pJson.isMember("tags"))
    {
        if(!validJsonOfField(3, "tags", pJson["tags"], err, false))
            return false;
    }
    if(pJson.isMember("content"))
    {
        if(!validJsonOfField(4, "content", pJson["content"], err, false))
            return false;
    }
    if(pJson.isMember("extra"))
    {
        if(!validJsonOfField(5, "extra", pJson["extra"], err, false))
            return false;
    }
    if(pJson.isMember("created"))
    {
        if(!validJsonOfField(6, "created", pJson["created"], err, false))
            return false;
    }
    return true;
}
bool Collection::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                                  const std::vector<std::string> &pMasqueradingVector,
                                                  std::string &err)
{
    if(pMasqueradingVector.size() != 7)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
      {
          if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
              return false;
      }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
      if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
      {
          if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
              return false;
      }
      if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
      {
          if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, false))
              return false;
      }
      if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
      {
          if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, false))
              return false;
      }
      if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
      {
          if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, false))
              return false;
      }
      if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
      {
          if(!validJsonOfField(5, pMasqueradingVector[5], pJson[pMasqueradingVector[5]], err, false))
              return false;
      }
      if(!pMasqueradingVector[6].empty() && pJson.isMember(pMasqueradingVector[6]))
      {
          if(!validJsonOfField(6, pMasqueradingVector[6], pJson[pMasqueradingVector[6]], err, false))
              return false;
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Collection::validJsonOfField(size_t index,
                                  const std::string &fieldName,
                                  const Json::Value &pJson,
                                  std::string &err,
                                  bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(isForCreation)
            {
                err="The automatic primary key cannot be set";
                return false;
            }
            if(!pJson.isInt64())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 2:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 3:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 4:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 5:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 6:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        default:
            err="Internal error in the server";
            return false;
            break;
    }
    return true;
}
