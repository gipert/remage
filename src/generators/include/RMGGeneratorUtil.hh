#ifndef _RMGGENERATORUTIL_HH
#define _RMGGENERATORUTIL_HH

#include "globals.hh"
#include "G4ThreeVector.hh"
#include "G4VSolid.hh"
#include "G4Box.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Tubs.hh"
#include "G4VPhysicalVolume.hh"

namespace RMGGeneratorUtil {

  G4bool IsSampleable(G4String g4_solid_type);

  G4ThreeVector rand(const G4VSolid*, G4bool on_surface=false);

  G4ThreeVector rand(const G4Box*, G4bool on_surface=false);

  G4ThreeVector rand(const G4Sphere*, G4bool on_surface=false);

  G4ThreeVector rand(const G4Orb*, G4bool on_surface=false);

  G4ThreeVector rand(const G4Tubs*, G4bool on_surface=false);
}

#endif

// vim: tabstop=2 shiftwidth=2 expandtab
