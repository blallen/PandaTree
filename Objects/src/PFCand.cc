#include "../interface/PFCand.h"

void
panda::PFCand::datastore::allocate(UInt_t _nmax)
{
  ParticleM::datastore::allocate(_nmax);

  charge = new Char_t[nmax_];
  puppiW = new Float_t[nmax_];
  puppiWNoLep = new Float_t[nmax_];
  pftype = new Int_t[nmax_];
}

void
panda::PFCand::datastore::deallocate()
{
  ParticleM::datastore::deallocate();

  delete [] charge;
  charge = 0;
  delete [] puppiW;
  puppiW = 0;
  delete [] puppiWNoLep;
  puppiWNoLep = 0;
  delete [] pftype;
  pftype = 0;
}

void
panda::PFCand::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  ParticleM::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "charge", _branches);
  utils::setStatus(_tree, _name, "puppiW", _branches);
  utils::setStatus(_tree, _name, "puppiWNoLep", _branches);
  utils::setStatus(_tree, _name, "pftype", _branches);
}

panda::utils::BranchList
panda::PFCand::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(ParticleM::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "charge"));
  blist.push_back(utils::getStatus(_tree, _name, "puppiW"));
  blist.push_back(utils::getStatus(_tree, _name, "puppiWNoLep"));
  blist.push_back(utils::getStatus(_tree, _name, "pftype"));

  return blist;
}

void
panda::PFCand::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "charge", charge, _branches, _setStatus);
  utils::setAddress(_tree, _name, "puppiW", puppiW, _branches, _setStatus);
  utils::setAddress(_tree, _name, "puppiWNoLep", puppiWNoLep, _branches, _setStatus);
  utils::setAddress(_tree, _name, "pftype", pftype, _branches, _setStatus);
}

void
panda::PFCand::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  ParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "charge", size, 'B', charge, _branches);
  utils::book(_tree, _name, "puppiW", size, 'F', puppiW, _branches);
  utils::book(_tree, _name, "puppiWNoLep", size, 'F', puppiWNoLep, _branches);
  utils::book(_tree, _name, "pftype", size, 'I', pftype, _branches);
}

void
panda::PFCand::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  ParticleM::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "charge");
  utils::resetAddress(_tree, _name, "puppiW");
  utils::resetAddress(_tree, _name, "puppiWNoLep");
  utils::resetAddress(_tree, _name, "pftype");
}

void
panda::PFCand::datastore::resizeVectors_(UInt_t _size)
{
  ParticleM::datastore::resizeVectors_(_size);

}

panda::PFCand::PFCand(char const* _name/* = ""*/) :
  ParticleM(new PFCandArray(1, _name)),
  charge(gStore.getData(this).charge[0]),
  puppiW(gStore.getData(this).puppiW[0]),
  puppiWNoLep(gStore.getData(this).puppiWNoLep[0]),
  pftype(gStore.getData(this).pftype[0])
{
}

panda::PFCand::PFCand(datastore& _data, UInt_t _idx) :
  ParticleM(_data, _idx),
  charge(_data.charge[_idx]),
  puppiW(_data.puppiW[_idx]),
  puppiWNoLep(_data.puppiWNoLep[_idx]),
  pftype(_data.pftype[_idx])
{
}

panda::PFCand::PFCand(PFCand const& _src) :
  ParticleM(new PFCandArray(1, gStore.getName(&_src))),
  charge(gStore.getData(this).charge[0]),
  puppiW(gStore.getData(this).puppiW[0]),
  puppiWNoLep(gStore.getData(this).puppiWNoLep[0]),
  pftype(gStore.getData(this).pftype[0])
{
  ParticleM::operator=(_src);

  charge = _src.charge;
  puppiW = _src.puppiW;
  puppiWNoLep = _src.puppiWNoLep;
  pftype = _src.pftype;
}

panda::PFCand::PFCand(ArrayBase* _array) :
  ParticleM(_array),
  charge(gStore.getData(this).charge[0]),
  puppiW(gStore.getData(this).puppiW[0]),
  puppiWNoLep(gStore.getData(this).puppiWNoLep[0]),
  pftype(gStore.getData(this).pftype[0])
{
}

panda::PFCand::~PFCand()
{
  destructor();
  gStore.free(this);
}

void
panda::PFCand::destructor()
{
  /* BEGIN CUSTOM PFCand.cc.destructor */
  /* END CUSTOM */

  ParticleM::destructor();
}

panda::PFCand&
panda::PFCand::operator=(PFCand const& _src)
{
  ParticleM::operator=(_src);

  charge = _src.charge;
  puppiW = _src.puppiW;
  puppiWNoLep = _src.puppiWNoLep;
  pftype = _src.pftype;

  return *this;
}

void
panda::PFCand::doSetStatus_(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  ParticleM::doSetStatus_(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "charge", _branches);
  utils::setStatus(_tree, _name, "puppiW", _branches);
  utils::setStatus(_tree, _name, "puppiWNoLep", _branches);
  utils::setStatus(_tree, _name, "pftype", _branches);
}

panda::utils::BranchList
panda::PFCand::doGetStatus_(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(ParticleM::doGetStatus_(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "charge"));
  blist.push_back(utils::getStatus(_tree, _name, "puppiW"));
  blist.push_back(utils::getStatus(_tree, _name, "puppiWNoLep"));
  blist.push_back(utils::getStatus(_tree, _name, "pftype"));

  return blist;
}

void
panda::PFCand::doSetAddress_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleM::doSetAddress_(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "charge", &charge, _branches, _setStatus);
  utils::setAddress(_tree, _name, "puppiW", &puppiW, _branches, _setStatus);
  utils::setAddress(_tree, _name, "puppiWNoLep", &puppiWNoLep, _branches, _setStatus);
  utils::setAddress(_tree, _name, "pftype", &pftype, _branches, _setStatus);
}

void
panda::PFCand::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ParticleM::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "charge", "", 'B', &charge, _branches);
  utils::book(_tree, _name, "puppiW", "", 'F', &puppiW, _branches);
  utils::book(_tree, _name, "puppiWNoLep", "", 'F', &puppiWNoLep, _branches);
  utils::book(_tree, _name, "pftype", "", 'I', &pftype, _branches);
}

void
panda::PFCand::doReleaseTree_(TTree& _tree, TString const& _name)
{
  ParticleM::doReleaseTree_(_tree, _name);

  utils::resetAddress(_tree, _name, "charge");
  utils::resetAddress(_tree, _name, "puppiW");
  utils::resetAddress(_tree, _name, "puppiWNoLep");
  utils::resetAddress(_tree, _name, "pftype");
}

void
panda::PFCand::doInit_()
{
  ParticleM::doInit_();

  charge = 0;
  puppiW = 0.;
  puppiWNoLep = 0.;
  pftype = 0;
}


/* BEGIN CUSTOM PFCand.cc.global */
/* END CUSTOM */
