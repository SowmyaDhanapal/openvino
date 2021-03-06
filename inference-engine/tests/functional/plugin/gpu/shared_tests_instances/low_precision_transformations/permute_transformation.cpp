// Copyright (C) 2020 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include <vector>

#include "low_precision_transformations/permute_transformation.hpp"
#include "common_test_utils/test_constants.hpp"

using namespace LayerTestsDefinitions;
using namespace ngraph::pass::low_precision;

namespace {
const std::vector<InferenceEngine::Precision> netPrecisions = {
        InferenceEngine::Precision::FP32
};

const std::vector<LayerTransformation::Params> trasformationParamValues = {
    LayerTestsUtils::LayerTransformationParamsFactory::createParams()
};

const std::vector<bool> perTensorValues = { true, false };

const std::vector<bool> transposeChannelDimValues = { true, false };

INSTANTIATE_TEST_CASE_P(DISABLED_smoke_LPT, PermuteTransformation,
    ::testing::Combine(
        ::testing::ValuesIn(netPrecisions),
        ::testing::Values(InferenceEngine::SizeVector({ 1, 3, 16, 16 })),
        ::testing::Values(CommonTestUtils::DEVICE_GPU),
        ::testing::ValuesIn(trasformationParamValues),
        ::testing::ValuesIn(perTensorValues),
        ::testing::ValuesIn(transposeChannelDimValues)),
    PermuteTransformation::getTestCaseName);
}  // namespace




