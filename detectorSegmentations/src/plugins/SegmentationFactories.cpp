#include "DD4hep/Factories.h"
#include "DD4hep/detail/SegmentationsInterna.h"

namespace {
template <typename T>
dd4hep::SegmentationObject* create_segmentation(const dd4hep::BitFieldCoder* decoder) {
  return new dd4hep::SegmentationWrapper<T>(decoder);
}
}

#include "detectorSegmentations/GridEta.h"
DECLARE_SEGMENTATION(GridEta, create_segmentation<dd4hep::DDSegmentation::GridEta>)

#include "detectorSegmentations/GridTheta.h"
DECLARE_SEGMENTATION(GridTheta, create_segmentation<dd4hep::DDSegmentation::GridTheta>)

#include "detectorSegmentations/FCCSWGridPhiTheta.h"
DECLARE_SEGMENTATION(FCCSWGridPhiTheta, create_segmentation<dd4hep::DDSegmentation::FCCSWGridPhiTheta>)

#include "detectorSegmentations/FCCSWGridPhiEta.h"
DECLARE_SEGMENTATION(FCCSWGridPhiEta, create_segmentation<dd4hep::DDSegmentation::FCCSWGridPhiEta>)

#include "detectorSegmentations/GridRPhiEta.h"
DECLARE_SEGMENTATION(GridRPhiEta, create_segmentation<dd4hep::DDSegmentation::GridRPhiEta>)

#include "detectorSegmentations/GridSimplifiedDriftChamber.h"
DECLARE_SEGMENTATION(GridSimplifiedDriftChamber, create_segmentation<dd4hep::DDSegmentation::GridSimplifiedDriftChamber>)

