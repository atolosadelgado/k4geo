#ifndef GRIDHYPERBOLOIDSTEREO_K4GEO_H
#define GRIDHYPERBOLOIDSTEREO_K4GEO_H

#include "DDSegmentation/Segmentation.h"
#include <DD4hep/detail/SegmentationsInterna.h>
#include <DD4hep/Objects.h> // For CellID, Vector3D
#include "DDSegmentation/BitFieldCoder.h"

namespace dd4hep {
namespace DDSegmentation {

class GridHyperboloidStereo_k4geo : public Segmentation {
public:
      /// Default constructor passing the encoding string
      GridHyperboloidStereo_k4geo(const std::string& cellEncoding);
      /// Default constructor used by derived classes passing an existing decoder
      GridHyperboloidStereo_k4geo(const BitFieldCoder* decoder);
      /// destructor
      virtual ~GridHyperboloidStereo_k4geo() = default;


    // Cell ID computation
    virtual CellID cellID(const Vector3D& localPosition,
                               const Vector3D& /* globalPosition */,
                               const VolumeID& vID) const;
    virtual Vector3D position(const CellID& cellID) const ;

    // Parameters setting and getting
    void setPhiBins(int bins);
    int phiBins() const;

    void setInnerRadius(double radius);
    double innerRadius() const;

    void setOuterRadius(double radius);
    double outerRadius() const;

    void setZMin(double zmin);
    double zMin() const;

    void setZMax(double zmax);
    double zMax() const;

    void setPhiBits(int bits);
    int phiBits() const;
//
private:
    int m_phiBins;
    double m_innerRadius;
    double m_outerRadius;
    double m_zMin;
    double m_zMax;
    int m_phiBits;
};

} // namespace DDSegmentation
} // namespace DD4hep

#endif // GRIDHYPERBOLOIDSTEREO_K4GEO_H
