/*
 * Copyright (C) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once

#include "shared/source/debug_settings/debug_settings_manager.h"
#include "shared/source/os_interface/driver_info.h"
#include "shared/source/os_interface/product_helper.h"

#include "level_zero/sysman/source/os_sysman.h"
#include <level_zero/zes_api.h>

#include <array>
#include <vector>

namespace L0 {
namespace Sysman {

class OsGlobalOperations {
  public:
    virtual bool getSerialNumber(char (&serialNumber)[ZES_STRING_PROPERTY_SIZE]) = 0;
    virtual bool getBoardNumber(char (&boardNumber)[ZES_STRING_PROPERTY_SIZE]) = 0;
    virtual void getBrandName(char (&brandName)[ZES_STRING_PROPERTY_SIZE]) = 0;
    virtual void getModelName(char (&modelName)[ZES_STRING_PROPERTY_SIZE]) = 0;
    virtual void getVendorName(char (&vendorName)[ZES_STRING_PROPERTY_SIZE]) = 0;
    virtual void getDriverVersion(char (&driverVersion)[ZES_STRING_PROPERTY_SIZE]) = 0;
    virtual void getWedgedStatus(zes_device_state_t *pState) = 0;
    virtual void getRepairStatus(zes_device_state_t *pState) = 0;
    virtual bool getUuid(std::array<uint8_t, NEO::ProductHelper::uuidSize> &uuid) = 0;
    virtual bool generateUuidFromPciBusInfo(const NEO::PhysicalDevicePciBusInfo &pciBusInfo, std::array<uint8_t, NEO::ProductHelper::uuidSize> &uuid) = 0;
    virtual ze_result_t reset(ze_bool_t force) = 0;
    virtual ze_result_t scanProcessesState(std::vector<zes_process_state_t> &pProcessList) = 0;
    virtual ze_result_t deviceGetState(zes_device_state_t *pState) = 0;
    static OsGlobalOperations *create(OsSysman *pOsSysman);
    virtual ~OsGlobalOperations() {}
};

} // namespace Sysman
} // namespace L0
