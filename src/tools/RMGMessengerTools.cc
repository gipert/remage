#include "RMGTools.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithABool.hh"

template <typename T>
std::unique_ptr<T> RMGTools::MakeG4UIcmd(G4String name, G4UImessenger* msg,
    std::vector<G4ApplicationState> avail_for, G4String unit_cat, G4String unit_cand, G4String par_name, G4String range) {

  std::unique_ptr<G4UIcmdWithADoubleAndUnit> cmd(new T(name.c_str(), msg));
  for (auto& s : avail_for) cmd->AvailableForStates(s);
  cmd->SetParameterName(par_name, false);
  cmd->SetUnitCategory(unit_cat);
  if (!unit_cand.empty()) cmd->SetUnitCandidates(unit_cand);
  if (!range.empty()) cmd->SetRange(range);

  return cmd;
}

template <typename T>
std::unique_ptr<T> RMGTools::MakeG4UIcmd(G4String name, G4UImessenger* msg,
    std::vector<G4ApplicationState> avail_for, G4String par_name, G4String range) {

  std::unique_ptr<G4UIcmdWithADoubleAndUnit> cmd(new T(name.c_str(), msg));
  for (auto& s : avail_for) cmd->AvailableForStates(s);
  cmd->SetParameterName(par_name, false);
  if (!range.empty()) cmd->SetRange(range);

  return cmd;
}

template <>
std::unique_ptr<G4UIcmdWithAString> RMGTools::MakeG4UIcmd<G4UIcmdWithAString>(G4String name, G4UImessenger* msg,
    std::vector<G4ApplicationState> avail_for, G4String candidates) {

  std::unique_ptr<G4UIcmdWithAString> cmd(new G4UIcmdWithAString(name.c_str(), msg));
  for (auto& s : avail_for) cmd->AvailableForStates(s);
  if (!candidates.empty()) cmd->SetCandidates(candidates);

  return cmd;
}

template <>
std::unique_ptr<G4UIcmdWithABool> RMGTools::MakeG4UIcmd(G4String name, G4UImessenger* msg,
    std::vector<G4ApplicationState> avail_for, G4bool default_val, G4bool omittable) {

  std::unique_ptr<G4UIcmdWithABool> cmd(new G4UIcmdWithABool(name.c_str(), msg));
  for (auto& s : avail_for) cmd->AvailableForStates(s);
  cmd->SetDefaultValue(default_val);
  cmd->SetParameterName("", omittable);

  return cmd;
}

// vim: shiftwidth=2 tabstop=2 expandtab 