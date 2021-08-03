#pragma once

#include "conditional-dependencies/shared/main.hpp"
#include "beatsaber-hook/shared/utils/typedefs.h"

#ifdef HAS_CODEGEN
    #include "UnityEngine/MonoBehaviour.hpp"
    #include "UnityEngine/Transform.hpp"
    #include "UnityEngine/Material.hpp"
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

namespace Qosmetics
{
    #ifdef HAS_CODEGEN
    class AltTrail : public UnityEngine::MonoBehaviour
    {
    #else
    #warning no codegen detected, class will fallback to manual definition
    class AltTrail : public Il2CppObject
    {
        void* m_CachedPtr;
    #endif
        public:
            Il2CppString* SortingLayerName;

            #ifdef HAS_CODEGEN
            UnityEngine::Transform* PointStart;
            UnityEngine::Transform* PointEnd;
            UnityEngine::Material* MyMaterial;
            #else
            Il2CppObject* PointStart;
            Il2CppObject* PointEnd;
            Il2CppObject* MyMaterial;
            #endif

            Il2CppObject* vertexPool;

            int SortingOrder;
            int TrailLength;
            int Granularity;
            float WhiteStep;

            COLOR MyColor;

        private:
            // dont even try accessing them lol, they're not in the order they appear here and they are mostly things that you shouldn't mess with anyways
            uint8_t privateMembers[sizeof(int) * 6 + sizeof(void*) * 3 + sizeof(std::vector<void*>) + sizeof(float) + sizeof(bool)];
    };
}
#undef COLOR
DEFINE_IL2CPP_ARG_TYPE(Qosmetics::AltTrail*, "Qosmetics", "AltTrail");