#ifndef PixelFitterByHelixProjections_H
#define PixelFitterByHelixProjections_H

#include "RecoPixelVertexing/PixelTrackFitting/interface/PixelFitter.h"
#include "DataFormats/TrackingRecHit/interface/TrackingRecHit.h"
#include "RecoTracker/TkTrackingRegions/interface/TrackingRegion.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/ESWatcher.h"

#include <vector>

//namespace edm {class ParameterSet;}
class TransientTrackingRecHitBuilder;
class TrackerGeometry;
class MagneticField;
class TrackerDigiGeometryRecord;
class IdealMagneticFieldRecord;
class TransientRecHitRecord;


class PixelFitterByHelixProjections : public PixelFitter {
public:
  PixelFitterByHelixProjections(  const edm::ParameterSet& cfg);
  virtual ~PixelFitterByHelixProjections() {}
    virtual reco::Track* run(
      const edm::EventSetup& es,
      const std::vector<const TrackingRecHit *>& hits,
      const TrackingRegion& region) const;
private:
  /* these are just static and local moved to local namespace in cc .... 
   *
  int charge(const std::vector<GlobalPoint> & points) const;
  float cotTheta(const GlobalPoint& pinner, const GlobalPoint& pouter) const;
  float phi(float xC, float yC, int charge) const;
  float pt(float curvature) const;
  float zip(float d0, float phi_p, float curv, 
    const GlobalPoint& pinner, const GlobalPoint& pouter) const;
  double errZip2(float apt, float eta) const;
  double errTip2(float apt, float eta) const;
  */
private:
  edm::ParameterSet theConfig;

  mutable const TrackerGeometry * theTracker;
  mutable const MagneticField * theField;
  mutable const TransientTrackingRecHitBuilder * theTTRecHitBuilder;

  mutable edm::ESWatcher<TrackerDigiGeometryRecord> theTrackerWatcher;
  mutable edm::ESWatcher<IdealMagneticFieldRecord> theFieldWatcher;
  mutable edm::ESWatcher<TransientRecHitRecord> theTTRecHitBuilderWatcher;
};
#endif
