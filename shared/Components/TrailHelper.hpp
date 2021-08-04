#pragma once

#include "conditional-dependencies/shared/main.hpp"
#include "beatsaber-hook/shared/utils/typedefs.h"

#ifdef COLOR_DEFINE 
#error COLOR_DEFINE macro defined, undefine it before including ColorComponent.hpp!
#endif

#ifdef HAS_CODEGEN
    #include "UnityEngine/MonoBehaviour.hpp"
#endif

#if defined __has_include && __has_include("sombrero/shared/ColorUtils.hpp")
    #include "sombrero/shared/ColorUtils.hpp"
    #define COLOR_DEFINE Sombrero::FastColor
#else
    #ifdef HAS_CODEGEN
        #include "UnityEngine/Color.hpp"
        #define COLOR_DEFINE UnityEngine::Color
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
        #define COLOR_DEFINE Color
    #endif
#endif
#include "AltTrail.hpp"

namespace Qosmetics
{
    #ifdef HAS_CODEGEN
    class TrailHelper : public UnityEngine::MonoBehaviour
    {
    #else
    #warning no codegen detected, class will fallback to manual definition
    class TrailHelper : public Il2CppObject
    {
        void* m_CachedPtr;
    #endif
        public:
            Qosmetics::AltTrail* trailInstance;
            // Qosmetics::ColorManager*
            Il2CppObject* colorManager;
            // GlobalNamespace::SaberModelController*
            Il2CppObject* parentModelController;
            
            void GetOrAddTrail(bool remake)
            {
                static auto function = CondDeps::FindUnsafe<void, TrailHelper*, bool>("questcosmetics", "TrailHelper_GetOrAddTrail");
                if (!function) return;

                function.value()(this, remake);
            }

            void Init(Il2CppObject* colorManager, Il2CppObject* saberModelController)
            {
                static auto function = CondDeps::FindUnsafe<void, TrailHelper*, Il2CppObject*, Il2CppObject*>("questcosmetics", "TrailHelper_Init");
                if (!function) return;

                function.value()(this, colorManager, saberModelController);
            }

            void TrailSetup()
            {
                static auto function = CondDeps::FindUnsafe<void, TrailHelper*>("questcosmetics", "TrailHelper_TrailSetup");
                if (!function) return;

                function.value()(this);
            }

            void SetTrailActive(bool active)
            {
                static auto function = CondDeps::FindUnsafe<void, TrailHelper*, bool>("questcosmetics", "TrailHelper_SetTrailActive");
                if (!function) return;

                function.value()(this, active);
            }

            void UpdateColors()
            {
                static auto function = CondDeps::FindUnsafe<void, TrailHelper*>("questcosmetics", "TrailHelper_UpdateColors");
                if (!function) return;

                function.value()(this);
            }

            COLOR_DEFINE GetColor(int colorType)
            {
                static auto function = CondDeps::FindUnsafe<void, TrailHelper*, int, COLOR_DEFINE&>("questcosmetics", "TrailHelper_GetColor");
                if (!function) 
                {
                    return {1.0f, 1.0f, 1.0f, 1.0f};
                }
                COLOR_DEFINE out;
                function.value()(this, colorType, out);
                return out;
            }

            void SetColors(const COLOR_DEFINE& leftColor, const COLOR_DEFINE& rightColor)
            {
                static auto function = CondDeps::FindUnsafe<void, TrailHelper*, const COLOR_DEFINE&, const COLOR_DEFINE&>("questcosmetics", "TrailHelper_SetColors");
                if (!function) return;
                
                function.value()(this, leftColor, rightColor);
            }

            int colorType;
            COLOR_DEFINE color;
            COLOR_DEFINE multiplier;
            int length;
            float whiteStep;
    };
}
#undef COLOR_DEFINE
DEFINE_IL2CPP_ARG_TYPE(Qosmetics::TrailHelper*, "Qosmetics", "TrailHelper");