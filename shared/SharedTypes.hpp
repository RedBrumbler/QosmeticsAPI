#pragma once

#include <string>

namespace Qosmetics
{
    enum ItemType {
        saber,
        note,
        wall,
        pointer,
        platform,
        invalid = 1000
    };

    struct NoteConfig {
        bool overrideNoteSize;
        double noteSize = 1.0f;
        bool alsoChangeHitboxes = false;
        bool forceDefaultBombs = false;
        bool forceDefaultDebris = false;
        bool disableReflections = false;
    };

    enum TrailType {
        custom,
        baseGame,
        none
    };

    struct SaberConfig {
        double saberWidth = 1.0f;
        bool overrideTrailLength = false;
        double trailLength = 14.0f;
        bool whiteTrail = false;
        bool overrideWhiteStep = false;
        double whiteStep = 0.1f;
        bool overrideTrailWidth = false;
        double trailWidth = 1.0f;
        bool enableMenuPointer = false;
        double menuPointerSize = 0.4f;
        TrailType trailType = TrailType::custom;
    };

    struct WallConfig {
        bool forceFakeGlowOff = false;
        bool forceCoreOff = false;
        bool forceFrameOff = false;
        bool disableReflections = false;
    };


    struct Config {
        SaberConfig saberConfig;
        NoteConfig noteConfig;
        WallConfig wallConfig;
        std::string lastActiveSaber = "";
        std::string lastActiveNote = "";
        std::string lastActiveWall = "";
    };

    class Descriptor {
        public: 
            std::string get_author()
            {
                return author; 
            }

            std::string get_name()
            {
                return name; 
            }

            std::string get_description()
            {
                return description; 
            }

            std::string get_filePath()
            {
                return filePath; 
            }

            ItemType get_type()
            {
                return type;
            } 

            bool get_isValid()
            {
                return type != invalid;
            }

        private:
            std::string author = "---";
            std::string name = "";
            std::string description = "";
            std::string filePath = "";
            ItemType type = invalid;
    };
}