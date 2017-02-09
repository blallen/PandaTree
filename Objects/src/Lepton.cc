#include "../interface/Lepton.h"

void
panda::Lepton::datastore::allocate(UInt_t _nmax)
{
  Particle::datastore::allocate(_nmax);

  q = new Short_t[nmax_];
  loose = new Bool_t[nmax_];
  medium = new Bool_t[nmax_];
  tight = new Bool_t[nmax_];
  chIso = new Float_t[nmax_];
  nhIso = new Float_t[nmax_];
  phIso = new Float_t[nmax_];
  puIso = new Float_t[nmax_];
  matchedGen_ = new Int_t[nmax_];
}

void
panda::Lepton::datastore::deallocate()
{
  Particle::datastore::deallocate();

  delete [] q;
  q = 0;
  delete [] loose;
  loose = 0;
  delete [] medium;
  medium = 0;
  delete [] tight;
  tight = 0;
  delete [] chIso;
  chIso = 0;
  delete [] nhIso;
  nhIso = 0;
  delete [] phIso;
  phIso = 0;
  delete [] puIso;
  puIso = 0;
  delete [] matchedGen_;
  matchedGen_ = 0;
}

void
panda::Lepton::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Particle::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "q", _branches);
  utils::setStatus(_tree, _name, "loose", _branches);
  utils::setStatus(_tree, _name, "medium", _branches);
  utils::setStatus(_tree, _name, "tight", _branches);
  utils::setStatus(_tree, _name, "chIso", _branches);
  utils::setStatus(_tree, _name, "nhIso", _branches);
  utils::setStatus(_tree, _name, "phIso", _branches);
  utils::setStatus(_tree, _name, "puIso", _branches);
  utils::setStatus(_tree, _name, "matchedGen_", _branches);
}

panda::utils::BranchList
panda::Lepton::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Particle::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "q"));
  blist.push_back(utils::getStatus(_tree, _name, "loose"));
  blist.push_back(utils::getStatus(_tree, _name, "medium"));
  blist.push_back(utils::getStatus(_tree, _name, "tight"));
  blist.push_back(utils::getStatus(_tree, _name, "chIso"));
  blist.push_back(utils::getStatus(_tree, _name, "nhIso"));
  blist.push_back(utils::getStatus(_tree, _name, "phIso"));
  blist.push_back(utils::getStatus(_tree, _name, "puIso"));
  blist.push_back(utils::getStatus(_tree, _name, "matchedGen_"));

  return blist;
}

void
panda::Lepton::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Particle::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "q", q, _branches, _setStatus);
  utils::setAddress(_tree, _name, "loose", loose, _branches, _setStatus);
  utils::setAddress(_tree, _name, "medium", medium, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tight", tight, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chIso", chIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhIso", nhIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phIso", phIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "puIso", puIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchedGen_", matchedGen_, _branches, _setStatus);
}

void
panda::Lepton::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Particle::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "q", size, 'S', q, _branches);
  utils::book(_tree, _name, "loose", size, 'O', loose, _branches);
  utils::book(_tree, _name, "medium", size, 'O', medium, _branches);
  utils::book(_tree, _name, "tight", size, 'O', tight, _branches);
  utils::book(_tree, _name, "chIso", size, 'F', chIso, _branches);
  utils::book(_tree, _name, "nhIso", size, 'F', nhIso, _branches);
  utils::book(_tree, _name, "phIso", size, 'F', phIso, _branches);
  utils::book(_tree, _name, "puIso", size, 'F', puIso, _branches);
  utils::book(_tree, _name, "matchedGen_", size, 'I', matchedGen_, _branches);
}

void
panda::Lepton::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  Particle::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "q");
  utils::resetAddress(_tree, _name, "loose");
  utils::resetAddress(_tree, _name, "medium");
  utils::resetAddress(_tree, _name, "tight");
  utils::resetAddress(_tree, _name, "chIso");
  utils::resetAddress(_tree, _name, "nhIso");
  utils::resetAddress(_tree, _name, "phIso");
  utils::resetAddress(_tree, _name, "puIso");
  utils::resetAddress(_tree, _name, "matchedGen_");
}

void
panda::Lepton::datastore::resizeVectors_(UInt_t _size)
{
  Particle::datastore::resizeVectors_(_size);

}

panda::Lepton::Lepton(char const* _name/* = ""*/) :
  Particle(new LeptonArray(1, _name)),
  q(gStore.getData(this).q[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  chIso(gStore.getData(this).chIso[0]),
  nhIso(gStore.getData(this).nhIso[0]),
  phIso(gStore.getData(this).phIso[0]),
  puIso(gStore.getData(this).puIso[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
}

panda::Lepton::Lepton(datastore& _data, UInt_t _idx) :
  Particle(_data, _idx),
  q(_data.q[_idx]),
  loose(_data.loose[_idx]),
  medium(_data.medium[_idx]),
  tight(_data.tight[_idx]),
  chIso(_data.chIso[_idx]),
  nhIso(_data.nhIso[_idx]),
  phIso(_data.phIso[_idx]),
  puIso(_data.puIso[_idx]),
  matchedGen(_data.matchedGenContainer_, _data.matchedGen_[_idx])
{
}

panda::Lepton::Lepton(Lepton const& _src) :
  Particle(new LeptonArray(1, gStore.getName(&_src))),
  q(gStore.getData(this).q[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  chIso(gStore.getData(this).chIso[0]),
  nhIso(gStore.getData(this).nhIso[0]),
  phIso(gStore.getData(this).phIso[0]),
  puIso(gStore.getData(this).puIso[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
  Particle::operator=(_src);

  q = _src.q;
  loose = _src.loose;
  medium = _src.medium;
  tight = _src.tight;
  chIso = _src.chIso;
  nhIso = _src.nhIso;
  phIso = _src.phIso;
  puIso = _src.puIso;
  matchedGen = _src.matchedGen;
}

panda::Lepton::Lepton(ArrayBase* _array) :
  Particle(_array),
  q(gStore.getData(this).q[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  chIso(gStore.getData(this).chIso[0]),
  nhIso(gStore.getData(this).nhIso[0]),
  phIso(gStore.getData(this).phIso[0]),
  puIso(gStore.getData(this).puIso[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
}

panda::Lepton::~Lepton()
{
  destructor();
  gStore.free(this);
}

void
panda::Lepton::destructor()
{
  /* BEGIN CUSTOM Lepton.cc.destructor */
  /* END CUSTOM */

  Particle::destructor();
}

panda::Lepton&
panda::Lepton::operator=(Lepton const& _src)
{
  Particle::operator=(_src);

  q = _src.q;
  loose = _src.loose;
  medium = _src.medium;
  tight = _src.tight;
  chIso = _src.chIso;
  nhIso = _src.nhIso;
  phIso = _src.phIso;
  puIso = _src.puIso;
  matchedGen = _src.matchedGen;

  return *this;
}

void
panda::Lepton::doSetStatus_(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Particle::doSetStatus_(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "q", _branches);
  utils::setStatus(_tree, _name, "loose", _branches);
  utils::setStatus(_tree, _name, "medium", _branches);
  utils::setStatus(_tree, _name, "tight", _branches);
  utils::setStatus(_tree, _name, "chIso", _branches);
  utils::setStatus(_tree, _name, "nhIso", _branches);
  utils::setStatus(_tree, _name, "phIso", _branches);
  utils::setStatus(_tree, _name, "puIso", _branches);
  utils::setStatus(_tree, _name, "matchedGen_", _branches);
}

panda::utils::BranchList
panda::Lepton::doGetStatus_(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Particle::doGetStatus_(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "q"));
  blist.push_back(utils::getStatus(_tree, _name, "loose"));
  blist.push_back(utils::getStatus(_tree, _name, "medium"));
  blist.push_back(utils::getStatus(_tree, _name, "tight"));
  blist.push_back(utils::getStatus(_tree, _name, "chIso"));
  blist.push_back(utils::getStatus(_tree, _name, "nhIso"));
  blist.push_back(utils::getStatus(_tree, _name, "phIso"));
  blist.push_back(utils::getStatus(_tree, _name, "puIso"));
  blist.push_back(utils::getStatus(_tree, _name, "matchedGen_"));

  return blist;
}

void
panda::Lepton::doSetAddress_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Particle::doSetAddress_(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "q", &q, _branches, _setStatus);
  utils::setAddress(_tree, _name, "loose", &loose, _branches, _setStatus);
  utils::setAddress(_tree, _name, "medium", &medium, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tight", &tight, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chIso", &chIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhIso", &nhIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phIso", &phIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "puIso", &puIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchedGen_", gStore.getData(this).matchedGen_, _branches, true);
}

void
panda::Lepton::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  Particle::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "q", "", 'S', &q, _branches);
  utils::book(_tree, _name, "loose", "", 'O', &loose, _branches);
  utils::book(_tree, _name, "medium", "", 'O', &medium, _branches);
  utils::book(_tree, _name, "tight", "", 'O', &tight, _branches);
  utils::book(_tree, _name, "chIso", "", 'F', &chIso, _branches);
  utils::book(_tree, _name, "nhIso", "", 'F', &nhIso, _branches);
  utils::book(_tree, _name, "phIso", "", 'F', &phIso, _branches);
  utils::book(_tree, _name, "puIso", "", 'F', &puIso, _branches);
  utils::book(_tree, _name, "matchedGen_", "", 'I', gStore.getData(this).matchedGen_, _branches);
}

void
panda::Lepton::doReleaseTree_(TTree& _tree, TString const& _name)
{
  Particle::doReleaseTree_(_tree, _name);

  utils::resetAddress(_tree, _name, "q");
  utils::resetAddress(_tree, _name, "loose");
  utils::resetAddress(_tree, _name, "medium");
  utils::resetAddress(_tree, _name, "tight");
  utils::resetAddress(_tree, _name, "chIso");
  utils::resetAddress(_tree, _name, "nhIso");
  utils::resetAddress(_tree, _name, "phIso");
  utils::resetAddress(_tree, _name, "puIso");
  utils::resetAddress(_tree, _name, "matchedGen_");
}

void
panda::Lepton::doInit_()
{
  Particle::doInit_();

  q = 0;
  loose = false;
  medium = false;
  tight = false;
  chIso = 0.;
  nhIso = 0.;
  phIso = 0.;
  puIso = 0.;
  matchedGen.init();
}


/* BEGIN CUSTOM Lepton.cc.global */
/* END CUSTOM */
