#include "detectorSegmentations/GridHyperboloidStereo_k4geo.h"
#include <DD4hep/Printout.h>
#include <cmath>

namespace dd4hep {
namespace DDSegmentation {

GridHyperboloidStereo_k4geo::GridHyperboloidStereo_k4geo(const std::string& cellEncoding):Segmentation(cellEncoding){}
GridHyperboloidStereo_k4geo::GridHyperboloidStereo_k4geo(const BitFieldCoder* decoder):Segmentation(decoder){}

CellID GridHyperboloidStereo_k4geo::cellID(const Vector3D& localPosition,
                               const Vector3D& /* globalPosition */,
                               const VolumeID& vID) const
{
    double phi = atan2(localPosition.y(), localPosition.x());
    if (phi < 0) phi += 2 * M_PI;
    int phiBin = static_cast<int>((phi / (2 * M_PI)) * m_phiBins);

    // Encode phiBin using the specified number of bits
    int maxPhiBin = (1 << m_phiBits) - 1;  // Maximum value that can be represented by m_phiBits
    if (phiBin > maxPhiBin) phiBin = maxPhiBin;  // Clamp to max value if exceeds
    CellID encodedPhiBin = phiBin & maxPhiBin;

    // Assuming cellID is encoded with phiBin in the least significant bits
    return (vID & (~maxPhiBin)) | encodedPhiBin;

}


Vector3D GridHyperboloidStereo_k4geo::position(const CellID& cellID) const
{
    int maxPhiBin = (1 << m_phiBits) - 1;  // Maximum value that can be represented by m_phiBits
    int phiBin = cellID & maxPhiBin;
    double phi = (phiBin + 0.5) * (2 * M_PI / m_phiBins);
    // Assume radius is the average of innerRadius and outerRadius
    double radius = (m_innerRadius + m_outerRadius) / 2.0;

    return Vector3D(radius * cos(phi), radius * sin(phi), 0.);

}

void GridHyperboloidStereo_k4geo::setPhiBins(int bins) { m_phiBins = bins; }
int GridHyperboloidStereo_k4geo::phiBins() const { return m_phiBins; }

void GridHyperboloidStereo_k4geo::setInnerRadius(double radius) { m_innerRadius = radius; }
double GridHyperboloidStereo_k4geo::innerRadius() const { return m_innerRadius; }

void GridHyperboloidStereo_k4geo::setOuterRadius(double radius) { m_outerRadius = radius; }
double GridHyperboloidStereo_k4geo::outerRadius() const { return m_outerRadius; }

void GridHyperboloidStereo_k4geo::setZMin(double zmin) { m_zMin = zmin; }
double GridHyperboloidStereo_k4geo::zMin() const { return m_zMin; }

void GridHyperboloidStereo_k4geo::setZMax(double zmax) { m_zMax = zmax; }
double GridHyperboloidStereo_k4geo::zMax() const { return m_zMax; }

void GridHyperboloidStereo_k4geo::setPhiBits(int bits) { m_phiBits = bits; }
int GridHyperboloidStereo_k4geo::phiBits() const { return m_phiBits; }

} // namespace DDSegmentation
} // namespace DD4hep
