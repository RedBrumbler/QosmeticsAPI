#pragma once

#include "conditional-dependencies/shared/main.hpp"
#include "SharedTypes.hpp"
#include <optional>
#include <functional>

#ifndef qosm_id
#define qosm_id "questcosmetics"
#endif

namespace Qosmetics
{
    class API
    {
        public:
            /// @brief Gets if Qosmetics even exists
            /// @return true for yes false for no
            static bool GetExists() noexcept
            {
                static auto function = CondDeps::FindUnsafe<bool>(qosm_id, "GetExists");
                if (!function) return false;
                else return true;
            }

            /// @brief Reloads the Descriptor cache so new files can be added
            /// @return method found
            static bool ReloadDescriptors()
            {
                static auto function = CondDeps::FindUnsafe<void>(qosm_id, "ReloadDescriptors");
                if (!function) return false;
                function.value()();
                return true;
            }

            /// @brief gets you the qosmetics config
            /// @return optional const ref config, nullopt for not found, const ref for found
            static std::optional<std::cref<Config>> GetConfig()
            {
                static auto function = CondDeps::FindUnsafe<Config*>(qosm_id, "GetConfig");
                if (!function) return std::nullopt;
                const Config& config = *function.value()();
                else return std::cref(config);
            }
    };
}
#undef qosm_id
