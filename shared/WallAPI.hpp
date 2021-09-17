#pragma once

#include "conditional-dependencies/shared/main.hpp"

#ifdef HAS_CODEGEN
#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/Material.hpp"
#include "UnityEngine/Mesh.hpp"
#else
#warning typedeffing unity classes as Il2CppObject so the header will work, this is ugly and you should honestly use codegen
namespace UnityEngine {
    typedef Il2CppObject GameObject;
    typedef Il2CppObject Material;
    typedef Il2CppObject Mesh;
}
#endif

#include "SharedTypes.hpp"

#include <optional>
#include <functional>

#ifndef qosm_id
#define qosm_id "questcosmetics"
#endif

namespace Qosmetics
{
    class WallAPI
    {
        public:
            /// @brief returns a reference to the ORIGINAL prefab used to instantiate all walls Qosmetics makes, please do not mess it up
            /// @return pointer to Main copy of Wall, nullopt on nonexistent, nullptr on default
            static std::optional<UnityEngine::GameObject*> GetActiveWallModel() noexcept
            {
                static auto function = CondDeps::FindUnsafe<UnityEngine::GameObject*>(qosm_id, "GetActiveWallModel");
                if (!function) return std::nullopt;
                UnityEngine::GameObject* result = function.value()();
                return std::make_optional(result);
            }

            /// @brief gets the core material array on the custom wall
            /// @return valid array on custom, nullptr on default, nullopt on nonexistent
            static std::optional<Array<UnityEngine::Material*>*> get_coreMaterials() noexcept
            {
                static auto function = CondDeps::FindUnsafe<Array<UnityEngine::Material*>*>(qosm_id, "get_coreMaterials");
                if (!function) return std::nullopt;
                Array<UnityEngine::Material*>* result = function.value()();
                return std::make_optional(result);
            }

            /// @brief gets the frame material array on the custom wall
            /// @return valid array on custom, nullptr on default, nullopt on nonexistent
            static std::optional<Array<UnityEngine::Material*>*> get_frameMaterials() noexcept
            {
                static auto function = CondDeps::FindUnsafe<Array<UnityEngine::Material*>*>(qosm_id, "get_frameMaterials");
                if (!function) return std::nullopt;
                Array<UnityEngine::Material*>* result = function.value()();
                return std::make_optional(result);
            }

            /// @brief gets the core mesh on the custom wall
            /// @return valid array on custom, nullptr on default, nullopt on nonexistent
            static std::optional<UnityEngine::Mesh*> get_coreMesh() noexcept
            {
                static auto function = CondDeps::FindUnsafe<UnityEngine::Mesh*>(qosm_id, "get_coreMesh");
                if (!function) return std::nullopt;
                UnityEngine::Mesh* result = function.value()();
                return std::make_optional(result);
            }

            /// @brief gets the frame mesh on the custom wall
            /// @return valid array on custom, nullptr on default, nullopt on nonexistent
            static std::optional<UnityEngine::Mesh*> get_frameMesh() noexcept
            {
                static auto function = CondDeps::FindUnsafe<UnityEngine::Mesh*>(qosm_id, "get_frameMesh");
                if (!function) return std::nullopt;
                UnityEngine::Mesh* result = function.value()();
                return std::make_optional(result);
            }

            /// @brief sets the default wall as the active wall
            static void SetDefault() noexcept
            {
                static auto function = CondDeps::FindUnsafe<void>(qosm_id, "SetDefaultWall");
                if (!function) return;
                function.value()();
            }

            /// @brief Sets active wall based on identifier (usually just the wall name)
            /// @param wall filename (without extension) of the wall
            static void SetActiveWall(std::string wall) noexcept
            {
                if (wall == "") return;
                static auto function = CondDeps::FindUnsafe<void, const char*>(qosm_id, "SetActiveWall");
                if (!function) return;
                function.value()(wall.c_str());
            }

            /// @brief Sets active wall based on full file path
            /// @param wallPath full path to the wall
            static void SetActiveWallFromFilePath(std::string wallPath) noexcept
            {
                if (wallPath == "") return;
                static auto function = CondDeps::FindUnsafe<void, const char*>(qosm_id, "SetActiveWallFromFilePath");
                if (!function) return;
                function.value()(wallPath.c_str());
            }

            /// @brief returns whether there's a custom wall, even with false the trails still get moved so keep that in mind!
            /// @return true for custom, false for default/nonexistent
            static std::optional<bool> GetWallIsCustom() noexcept
            {
                static auto function = CondDeps::FindUnsafe<bool>(qosm_id, "GetWallIsCustom");
                if (!function) return std::nullopt;
                return std::make_optional(function.value()());
            }

            /// @brief returns the filepath to the Qosmetics notes folder, in case it ever gets moved
            /// @return string folder path, or nullopt for not installed
            static std::optional<std::string> GetWallFolder()
            {
                static auto function = CondDeps::FindUnsafe<void, std::string&>(qosm_id, "GetWallFolder");
                if (!function) return std::nullopt;
                std::string result = "";
                function.value()(result);
                return std::make_optional(result);
            }

            /// @brief gets active wall descriptor, allowing you to get some more info about the wall
            /// @return optional descriptor, nullopt for not found, valid for found
            static std::optional<Descriptor> GetActiveWallDescriptor()
            {
                static auto function = CondDeps::FindUnsafe<Descriptor>(qosm_id, "GetActiveWallDescriptor");
                if (!function) return std::nullopt;
                else return function.value()();
            }

            /// @brief gets whether or not walls are forcibly disabled by some mod
            /// @return optional bool, true for disabled, false for not disabled, nullopt for not installed
            static std::optional<bool> GetWallsDisabled()
            {
                static auto function = CondDeps::FindUnsafe<bool>(qosm_id, "GetWallsDisabled");
                if (!function) return std::nullopt;
                else return function.value()();
            }

            /// @brief registers a mod as disabling walls, making Qosmetics do nothing with notes
            /// @param info the modinfo to pass to the disabling function
            static void RegisterWallDisablingInfo(ModInfo info)
            {
                static auto function = CondDeps::FindUnsafe<void, ModInfo>(qosm_id, "RegisterWallDisablingInfo");
                if (!function) return;
                else function.value()(info);
            }

            /// @brief unregisters a mod as disabling walls, allowing qosmetics, provided no other mods also disable 
            /// @param info the modinfo to pass to the disabling function
            static void UnregisterWallDisablingInfo(ModInfo info)
            {
                static auto function = CondDeps::FindUnsafe<void, ModInfo>(qosm_id, "UnregisterWallDisablingInfo");
                if (!function) return;
                else function.value()(info);
            }
    };
}