/* Copyright (C) 2006 - 2011 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software licensed under GPL version 2
* Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_OUTDOOR_PVP_H
#define SC_OUTDOOR_PVP_H

#include "InstanceData.h"
#include "Map.h"

#define OUT_SAVE_PVP_DATA             debug_log("SD2: Saving OutdoorPvP Data for Instance %s (Map %d, Instance Id %d)", instance->GetMapName(), instance->GetId(), instance->GetInstanceId())
#define OUT_SAVE_PVP_DATA_COMPLETE    debug_log("SD2: Saving OutdoorPvP Data for Instance %s (Map %d, Instance Id %d) completed.", instance->GetMapName(), instance->GetId(), instance->GetInstanceId())
#define OUT_LOAD_PVP_DATA(a)          debug_log("SD2: Loading OutdoorPvP Data for Instance %s (Map %d, Instance Id %d). Input is '%s'", instance->GetMapName(), instance->GetId(), instance->GetInstanceId(), a)
#define OUT_LOAD_PVP_DATA_COMPLETE    debug_log("SD2: OutdoorPvP Data Load for Instance %s (Map %d, Instance Id: %d) is complete.",instance->GetMapName(), instance->GetId(), instance->GetInstanceId())
#define OUT_LOAD_PVP_DATA_FAIL        error_log("SD2: Unable to load OutdoorPvP Data for Instance %s (Map %d, Instance Id: %d).",instance->GetMapName(), instance->GetId(), instance->GetInstanceId())

enum CaptureState
{
    NEUTRAL     = 0,
    PROGRESS    = 1,
    CONTESTED   = 2,
    WIN         = 3
};

class MANGOS_DLL_DECL OutdoorPvP : public InstanceData
{
    public:
        OutdoorPvP(Map* pMap) : InstanceData(pMap) {}
        ~OutdoorPvP() {}

        typedef std::set<uint64 /* playerGUID */> PlayerSet;

        // Sends world state update to all players in the current zone; they are stored in a PlayerSet
        void DoUpdateWorldState(PlayerSet sPlayerSet, uint32 uiStateId, uint32 uiStateData);

        // Get a Player from map, depending on zone
        Player* GetPlayerInMap(PlayerSet sPlayerSet, bool bOnlyAlive = false, bool bCanBeGamemaster = true);

        // Process a spell a spell event (cast or remove) to a specific team in a specific zone;  they are stored in a PlayerSet
        void DoProcessTeamBuff(PlayerSet sPlayerSet, Team uiTeamId, uint32 uiSpellId, bool bRemove = false);
};
#endif
