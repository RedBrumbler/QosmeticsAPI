#pragma once

#include "conditional-dependencies/shared/main.hpp"
#include <optional>
#include <functional>

#ifndef qosm_id
#define qosm_id "questcosmetics"
#endif

namespace Qosmetic
{
    class API
    {
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
    };
}
#undef qosm_id