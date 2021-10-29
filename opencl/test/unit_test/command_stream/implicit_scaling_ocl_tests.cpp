/*
 * Copyright (C) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "shared/source/command_container/implicit_scaling.h"

#include "test.h"

using namespace NEO;

TEST(ImplicitScalingApiTests, givenOpenClApiUsedThenSupportEnabled) {
    EXPECT_TRUE(ImplicitScaling::apiSupport);
}
