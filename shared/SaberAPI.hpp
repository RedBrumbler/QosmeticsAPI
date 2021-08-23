#pragma once

#include "conditional-dependencies/shared/main.hpp"
#include <optional>
#include <functional>

#ifdef HAS_CODEGEN
#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/Transform.hpp"
#else
#warning typedeffing unity classes as Il2CppObject so the header will work, this is ugly and you should honestly use codegen
namespace UnityEngine {
    typedef Il2CppObject GameObject;
    typedef Il2CppObject Transform;
}
#endif

#include "SharedTypes.hpp"

#ifndef qosm_id
#define qosm_id "questcosmetics"
#endif

namespace Qosmetics
{
    class SaberAPI
    {
        public:
            /// @brief returns a reference to the ORIGINAL prefab used to instantiate all sabers Qosmetics makes, please do not mess it up
            /// @return pointer to Main copy of Saber, nullopt on nonexistent, nullptr on default
            static std::optional<UnityEngine::GameObject*> GetActiveSaberModel() noexcept
            {
                static auto function = CondDeps::FindUnsafe<UnityEngine::GameObject*>(qosm_id, "GetActiveSaberModel");

                if (!function) return std::nullopt;

                UnityEngine::GameObject* result = function.value()();
                return std::make_optional(result);
            }

            /// @brief returns a copy of the left or right saber depending on the type you give, with trails!
            /// @param type 0 or 1 for left or right
            /// @return transform of a COPY of the left or right saber with trails, nullopt on nonexistent, nullptr on default
            static std::optional<UnityEngine::Transform*> GetDummySaber(int type) noexcept
            {
                if (type < 0 || type > 1) return std::nullopt;
                static auto function = CondDeps::FindUnsafe<UnityEngine::Transform*, int>(qosm_id, "GetDummySaber");
                if (!function) return std::nullopt;
                UnityEngine::Transform* result = function.value()(type);
                return std::make_optional(result);
            }

            /// @brief returns a copy of the left or right saber depending on the type you give, no trails!
            /// @param type 0 or 1 for left or right
            /// @return transform of a COPY of the left or right saber, nullopt on nonexistent, nullptr on default
            static std::optional<UnityEngine::Transform*> get_saber(int type) noexcept
            {
                if (type < 0 || type > 1) return std::nullopt;
                static auto function = CondDeps::FindUnsafe<UnityEngine::Transform*, int>(qosm_id, "get_saber");
                if (!function) return std::nullopt;
                UnityEngine::Transform* result = function.value()(type);
                return std::make_optional(result);
            }

            /// @brief sets the default saber as the active saber
            static void SetDefault() noexcept
            {
                static auto function = CondDeps::FindUnsafe<void>(qosm_id, "SetDefaultSaber");
                if (!function) return;
                function.value()();
            }

            /// @brief Sets active saber based on identifier (usually just the saber name)
            /// @param saber filename (without extension) of the saber
            static void SetActiveSaber(std::string saber) noexcept
            {
                if (saber == "") return;
                static auto function = CondDeps::FindUnsafe<void, const char*>(qosm_id, "SetActiveSaber");
                if (!function) return;
                function.value()(saber.c_str());
            }

            /// @brief Sets active saber based on full file path
            /// @param saberPath full path to the saber
            static void SetActiveSaberFromFilePath(std::string saberPath) noexcept
            {
                if (saberPath == "") return;
                static auto function = CondDeps::FindUnsafe<void, const char*>(qosm_id, "SetActiveSaberFromFilePath");
                if (!function) return;
                function.value()(saberPath.c_str());
            }

            /// @brief returns whether there's a custom saber, even with false the trails still get moved so keep that in mind!
            /// @return true for custom, false for default, nullopt for nonexistent
            static std::optional<bool> GetSaberIsCustom() noexcept
            {
                static auto function = CondDeps::FindUnsafe<bool>(qosm_id, "GetSaberIsCustom");
                if (!function) return std::nullopt;
                return std::make_optional(function.value()());
            }

            /// @brief returns the filepath to the Qosmetics sabers folder, in case it ever gets moved
            /// @return string folder path, or nullopt for not installed
            static std::optional<std::string> GetSaberFolder()
            {
                static auto function = CondDeps::FindUnsafe<void, std::string&>(qosm_id, "GetSaberFolder");
                if (!function) return std::nullopt;
                std::string result = "";
                function.value()(result);
                return std::make_optional(result);
            }

            /// @brief gets active saber descriptor, allowing you to get some more info about the saber
            /// @return optional descriptor, nullopt for not found, valid for found
            static std::optional<Descriptor> GetActiveSaberDescriptor()
            {
                static auto function = CondDeps::FindUnsafe<Descriptor>(qosm_id, "GetActiveSaberDescriptor");
                if (!function) return std::nullopt;
                else return function.value()();
            }
    };
}