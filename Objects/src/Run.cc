#include "../interface/Run.h"

panda::Run::Run() :
  TreeEntry("Run")
{
}

panda::Run::Run(Run const& _src) :
  TreeEntry(_src.getName()),
  run(_src.run),
  hltMenu(_src.hltMenu)
{
}

panda::Run&
panda::Run::operator=(Run const& _src)
{
  run = _src.run;
  hltMenu = _src.hltMenu;

  return *this;
}

/*protected*/
void
panda::Run::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::setStatus(_tree, "", "run", _branches);
  utils::setStatus(_tree, "", "hltMenu", _branches);
}

/*protected*/
panda::utils::BranchList
panda::Run::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;

  blist.push_back(utils::getStatus(_tree, "", "run"));
  blist.push_back(utils::getStatus(_tree, "", "hltMenu"));
  return blist;
}

/*protected*/
void
panda::Run::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)
{
  utils::setAddress(_tree, "", "run", &run, _branches, _setStatus);
  utils::setAddress(_tree, "", "hltMenu", &hltMenu, _branches, _setStatus);
}

/*protected*/
void
panda::Run::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::book(_tree, "", "run", "", 'i', &run, _branches);
  utils::book(_tree, "", "hltMenu", "", 'i', &hltMenu, _branches);
}

/*protected*/
void
panda::Run::doReleaseTree_(TTree& _tree)
{
  utils::resetAddress(_tree, "", "run");
  utils::resetAddress(_tree, "", "hltMenu");
}

void
panda::Run::doInit_()
{
  run = 0;
  hltMenu = 0;
}


/* BEGIN CUSTOM Run.cc.global */
/* END CUSTOM */
