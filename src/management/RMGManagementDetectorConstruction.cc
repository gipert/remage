#include "RMGManagementDetectorConstruction.hh"

#include "G4VPhysicalVolume.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4UserLimits.hh"

#include "RMGMaterialTable.hh"

RMGMaterialTable::BathMaterial RMGManagementDetectorConstruction::fBathMaterial = RMGMaterialTable::BathMaterial::kNone;

RMGManagementDetectorConstruction::RMGManagementDetectorConstruction() {

  fMaterialTable = std::unique_ptr<RMGMaterialTable>(new RMGMaterialTable());
}

G4VPhysicalVolume* RMGManagementDetectorConstruction::Construct() {

  this->DefineGeometry();

  // TODO: build and return world volume?

  for (auto v : *G4PhysicalVolumeStore::GetInstance()) {
    auto max_step = fPhysVolStepLimits.at(v->GetName());
    if (max_step > 0) {
      v->GetLogicalVolume()->SetUserLimits(new G4UserLimits(max_step));
    }
  }

  // TODO
  return nullptr;
}

void RMGManagementDetectorConstruction::ConstructSDandField() {
  // TODO
}

// vim: tabstop=2 shiftwidth=2 expandtab
