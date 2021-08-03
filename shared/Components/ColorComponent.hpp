#pragma once

#include "conditional-dependencies/shared/main.hpp"
#include "beatsaber-hook/shared/utils/typedefs.h"

#ifdef COLOR 
    #error COLOR macro defined, undefine it before including ColorComponent.hpp!
#endif

#ifdef HAS_CODEGEN
    #include "UnityEngine/MonoBehaviour.hpp"
#endif

#if defined __has_include && __has_include("sombrero/shared/ColorUtils.hpp")
    #include "sombrero/shared/ColorUtils.hpp"
    #define COLOR Sombrero::FastColor
#else
    #ifdef HAS_CODEGEN
        #include "UnityEngine/Color.hpp"
        #define COLOR UnityEngine::Color
    #else
        #ifndef QOS_COLOR
        #define QOS_COLOR
        #warning defining qosmetics color type, this is not recommended to be used, but can be used. Use codegen or Sombrero instead
        struct Color {
            float r;
            float g;
            float b;
            float a;
        };
        DEFINE_IL2CPP_ARG_TYPE(Color, "UnityEngine", "Color");
        #endif
        #define COLOR Color
    #endif
#endif

#ifndef qosm_id
    #define qosm_id "questcosmetics"
#endif

namespace Qosmetics
{
    #ifdef HAS_CODEGEN
    class ColorComponent : public UnityEngine::MonoBehaviour
    {
    #else
    #warning no codegen detected, class will fallback to manual definition
    class ColorComponent : public Il2CppObject
    {
        void* m_CachedPtr;
    #endif
        public:
            /// @brief give a left and right color to use for this object
            void SetColors(const COLOR& leftColor, const COLOR& rightColor)
            {
                static auto function = CondDeps::FindUnsafe<void, Il2CppObject*, COLOR, COLOR>(qosm_id, "ColorComponent_SetColors");
                if (!function) return;

                function.value()(this, leftColor, rightColor);
            }

            /// @brief call this to let qosmetics handle the colors itself
            void UpdateColors()
            {
                static auto function = CondDeps::FindUnsafe<void, Il2CppObject*>(qosm_id, "ColorComponent_UpdateColors");
                if (!function) return;

                function.value()(this);
            }
            // Qosmetics::ColorManager*
            Il2CppObject* colorManager;
            // 0 saber
            // 1 note
            // 2 wall
            int objectType;
            // 0 left
            // 1 right
            int colorType;
    };
}
#undef qosm_id
#undef COLOR
DEFINE_IL2CPP_ARG_TYPE(Qosmetics::ColorComponent*, "Qosmetics", "ColorComponent");
