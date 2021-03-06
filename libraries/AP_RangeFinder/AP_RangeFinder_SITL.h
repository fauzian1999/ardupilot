/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include <AP_BoardConfig/AP_BoardConfig.h>

#ifndef AP_SIM_RANGEFINDER_ENABLED
#define AP_SIM_RANGEFINDER_ENABLED (AP_SIM_ENABLED && !defined(HAL_BUILD_AP_PERIPH))
#endif

#if AP_SIM_RANGEFINDER_ENABLED

#include "AP_RangeFinder_Backend.h"

#include <SITL/SITL.h>

class AP_RangeFinder_SITL : public AP_RangeFinder_Backend {
public:
    // constructor. This incorporates initialisation as well.
    AP_RangeFinder_SITL(RangeFinder::RangeFinder_State &_state, AP_RangeFinder_Params &_params, uint8_t instance);

    // update the state structure
    void update() override;

protected:

    MAV_DISTANCE_SENSOR _get_mav_distance_sensor_type() const override {
        return MAV_DISTANCE_SENSOR_UNKNOWN;
    }

private:
    SITL::SIM *sitl;

    uint8_t _instance;

};

#endif  // AP_SIM_RANGEFINDER_ENABLED
