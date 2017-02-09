#include "../interface/Photon.h"

/*static*/
double const chIsoCuts[2][2][4]{{{3.32, 1.37, 0.76, 5.0}, {1.97, 1.10, 0.56, 5.0}},                  {{1.295, 0.441, 0.202, 5.0}, {1.011, 0.442, 0.034, 5.0}}};
/*static*/
double const nhIsoCuts[2][2][4]{{{1.92, 1.06, 0.97, 100000.}, {11.86, 2.69, 2.09, 100000.}},         {{10.910, 2.725, 0.264, 100000.}, {5.931, 1.715, 0.586, 100000.}}};
/*static*/
double const phIsoCuts[2][2][4]{{{0.81, 0.28, 0.08, 2.75}, {0.83, 0.39, 0.16, 2.00}},                {{3.630, 2.571, 2.362, 2.75}, {6.641, 3.863, 2.617, 2.00}}};
/*static*/
double const sieieCuts[2][2][4]{{{0.0102, 0.0102, 0.0100, 0.0105}, {0.0274, 0.0268, 0.0268, 0.028}}, {{0.01031, 0.01022, 0.00994, 0.0105}, {0.03013, 0.03001, 0.03000, 0.028}}};
/*static*/
double const hOverECuts[2][2][4]{{{0.05, 0.05, 0.05, 0.05}, {0.05, 0.05, 0.05, 0.05}},               {{0.0597, 0.0396, 0.0269, 0.05}, {0.0481, 0.0219, 0.0213, 0.05}}};

void
panda::Photon::datastore::allocate(UInt_t _nmax)
{
  Particle::datastore::allocate(_nmax);

  scRawPt = new Float_t[nmax_];
  chIso = new Float_t[nmax_];
  chIsoMax = new Float_t[nmax_];
  nhIso = new Float_t[nmax_];
  phIso = new Float_t[nmax_];
  chIsoS15 = new Float_t[nmax_];
  nhIsoS15 = new Float_t[nmax_];
  phIsoS15 = new Float_t[nmax_];
  sieie = new Float_t[nmax_];
  sipip = new Float_t[nmax_];
  hOverE = new Float_t[nmax_];
  genIso = new Float_t[nmax_];
  mipEnergy = new Float_t[nmax_];
  e33 = new Float_t[nmax_];
  e4 = new Float_t[nmax_];
  eseed = new Float_t[nmax_];
  emax = new Float_t[nmax_];
  e2nd = new Float_t[nmax_];
  r9 = new Float_t[nmax_];
  etaWidth = new Float_t[nmax_];
  phiWidth = new Float_t[nmax_];
  time = new Float_t[nmax_];
  timeSpan = new Float_t[nmax_];
  loose = new Bool_t[nmax_];
  medium = new Bool_t[nmax_];
  tight = new Bool_t[nmax_];
  highpt = new Bool_t[nmax_];
  isEB = new Bool_t[nmax_];
  pixelVeto = new Bool_t[nmax_];
  csafeVeto = new Bool_t[nmax_];
  triggerMatch = new Bool_t[nmax_][nPhotonTriggerObjects];
  superCluster_ = new Int_t[nmax_];
  matchedGen_ = new Int_t[nmax_];
}

void
panda::Photon::datastore::deallocate()
{
  Particle::datastore::deallocate();

  delete [] scRawPt;
  scRawPt = 0;
  delete [] chIso;
  chIso = 0;
  delete [] chIsoMax;
  chIsoMax = 0;
  delete [] nhIso;
  nhIso = 0;
  delete [] phIso;
  phIso = 0;
  delete [] chIsoS15;
  chIsoS15 = 0;
  delete [] nhIsoS15;
  nhIsoS15 = 0;
  delete [] phIsoS15;
  phIsoS15 = 0;
  delete [] sieie;
  sieie = 0;
  delete [] sipip;
  sipip = 0;
  delete [] hOverE;
  hOverE = 0;
  delete [] genIso;
  genIso = 0;
  delete [] mipEnergy;
  mipEnergy = 0;
  delete [] e33;
  e33 = 0;
  delete [] e4;
  e4 = 0;
  delete [] eseed;
  eseed = 0;
  delete [] emax;
  emax = 0;
  delete [] e2nd;
  e2nd = 0;
  delete [] r9;
  r9 = 0;
  delete [] etaWidth;
  etaWidth = 0;
  delete [] phiWidth;
  phiWidth = 0;
  delete [] time;
  time = 0;
  delete [] timeSpan;
  timeSpan = 0;
  delete [] loose;
  loose = 0;
  delete [] medium;
  medium = 0;
  delete [] tight;
  tight = 0;
  delete [] highpt;
  highpt = 0;
  delete [] isEB;
  isEB = 0;
  delete [] pixelVeto;
  pixelVeto = 0;
  delete [] csafeVeto;
  csafeVeto = 0;
  delete [] triggerMatch;
  triggerMatch = 0;
  delete [] superCluster_;
  superCluster_ = 0;
  delete [] matchedGen_;
  matchedGen_ = 0;
}

void
panda::Photon::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Particle::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "scRawPt", _branches);
  utils::setStatus(_tree, _name, "chIso", _branches);
  utils::setStatus(_tree, _name, "chIsoMax", _branches);
  utils::setStatus(_tree, _name, "nhIso", _branches);
  utils::setStatus(_tree, _name, "phIso", _branches);
  utils::setStatus(_tree, _name, "chIsoS15", _branches);
  utils::setStatus(_tree, _name, "nhIsoS15", _branches);
  utils::setStatus(_tree, _name, "phIsoS15", _branches);
  utils::setStatus(_tree, _name, "sieie", _branches);
  utils::setStatus(_tree, _name, "sipip", _branches);
  utils::setStatus(_tree, _name, "hOverE", _branches);
  utils::setStatus(_tree, _name, "genIso", _branches);
  utils::setStatus(_tree, _name, "mipEnergy", _branches);
  utils::setStatus(_tree, _name, "e33", _branches);
  utils::setStatus(_tree, _name, "e4", _branches);
  utils::setStatus(_tree, _name, "eseed", _branches);
  utils::setStatus(_tree, _name, "emax", _branches);
  utils::setStatus(_tree, _name, "e2nd", _branches);
  utils::setStatus(_tree, _name, "r9", _branches);
  utils::setStatus(_tree, _name, "etaWidth", _branches);
  utils::setStatus(_tree, _name, "phiWidth", _branches);
  utils::setStatus(_tree, _name, "time", _branches);
  utils::setStatus(_tree, _name, "timeSpan", _branches);
  utils::setStatus(_tree, _name, "loose", _branches);
  utils::setStatus(_tree, _name, "medium", _branches);
  utils::setStatus(_tree, _name, "tight", _branches);
  utils::setStatus(_tree, _name, "highpt", _branches);
  utils::setStatus(_tree, _name, "isEB", _branches);
  utils::setStatus(_tree, _name, "pixelVeto", _branches);
  utils::setStatus(_tree, _name, "csafeVeto", _branches);
  utils::setStatus(_tree, _name, "triggerMatch", _branches);
  utils::setStatus(_tree, _name, "superCluster_", _branches);
  utils::setStatus(_tree, _name, "matchedGen_", _branches);
}

panda::utils::BranchList
panda::Photon::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Particle::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "scRawPt"));
  blist.push_back(utils::getStatus(_tree, _name, "chIso"));
  blist.push_back(utils::getStatus(_tree, _name, "chIsoMax"));
  blist.push_back(utils::getStatus(_tree, _name, "nhIso"));
  blist.push_back(utils::getStatus(_tree, _name, "phIso"));
  blist.push_back(utils::getStatus(_tree, _name, "chIsoS15"));
  blist.push_back(utils::getStatus(_tree, _name, "nhIsoS15"));
  blist.push_back(utils::getStatus(_tree, _name, "phIsoS15"));
  blist.push_back(utils::getStatus(_tree, _name, "sieie"));
  blist.push_back(utils::getStatus(_tree, _name, "sipip"));
  blist.push_back(utils::getStatus(_tree, _name, "hOverE"));
  blist.push_back(utils::getStatus(_tree, _name, "genIso"));
  blist.push_back(utils::getStatus(_tree, _name, "mipEnergy"));
  blist.push_back(utils::getStatus(_tree, _name, "e33"));
  blist.push_back(utils::getStatus(_tree, _name, "e4"));
  blist.push_back(utils::getStatus(_tree, _name, "eseed"));
  blist.push_back(utils::getStatus(_tree, _name, "emax"));
  blist.push_back(utils::getStatus(_tree, _name, "e2nd"));
  blist.push_back(utils::getStatus(_tree, _name, "r9"));
  blist.push_back(utils::getStatus(_tree, _name, "etaWidth"));
  blist.push_back(utils::getStatus(_tree, _name, "phiWidth"));
  blist.push_back(utils::getStatus(_tree, _name, "time"));
  blist.push_back(utils::getStatus(_tree, _name, "timeSpan"));
  blist.push_back(utils::getStatus(_tree, _name, "loose"));
  blist.push_back(utils::getStatus(_tree, _name, "medium"));
  blist.push_back(utils::getStatus(_tree, _name, "tight"));
  blist.push_back(utils::getStatus(_tree, _name, "highpt"));
  blist.push_back(utils::getStatus(_tree, _name, "isEB"));
  blist.push_back(utils::getStatus(_tree, _name, "pixelVeto"));
  blist.push_back(utils::getStatus(_tree, _name, "csafeVeto"));
  blist.push_back(utils::getStatus(_tree, _name, "triggerMatch"));
  blist.push_back(utils::getStatus(_tree, _name, "superCluster_"));
  blist.push_back(utils::getStatus(_tree, _name, "matchedGen_"));

  return blist;
}

void
panda::Photon::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Particle::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "scRawPt", scRawPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chIso", chIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chIsoMax", chIsoMax, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhIso", nhIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phIso", phIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chIsoS15", chIsoS15, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhIsoS15", nhIsoS15, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phIsoS15", phIsoS15, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sieie", sieie, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sipip", sipip, _branches, _setStatus);
  utils::setAddress(_tree, _name, "hOverE", hOverE, _branches, _setStatus);
  utils::setAddress(_tree, _name, "genIso", genIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mipEnergy", mipEnergy, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e33", e33, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e4", e4, _branches, _setStatus);
  utils::setAddress(_tree, _name, "eseed", eseed, _branches, _setStatus);
  utils::setAddress(_tree, _name, "emax", emax, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e2nd", e2nd, _branches, _setStatus);
  utils::setAddress(_tree, _name, "r9", r9, _branches, _setStatus);
  utils::setAddress(_tree, _name, "etaWidth", etaWidth, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phiWidth", phiWidth, _branches, _setStatus);
  utils::setAddress(_tree, _name, "time", time, _branches, _setStatus);
  utils::setAddress(_tree, _name, "timeSpan", timeSpan, _branches, _setStatus);
  utils::setAddress(_tree, _name, "loose", loose, _branches, _setStatus);
  utils::setAddress(_tree, _name, "medium", medium, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tight", tight, _branches, _setStatus);
  utils::setAddress(_tree, _name, "highpt", highpt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "isEB", isEB, _branches, _setStatus);
  utils::setAddress(_tree, _name, "pixelVeto", pixelVeto, _branches, _setStatus);
  utils::setAddress(_tree, _name, "csafeVeto", csafeVeto, _branches, _setStatus);
  utils::setAddress(_tree, _name, "triggerMatch", triggerMatch, _branches, _setStatus);
  utils::setAddress(_tree, _name, "superCluster_", superCluster_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchedGen_", matchedGen_, _branches, _setStatus);
}

void
panda::Photon::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Particle::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "scRawPt", size, 'F', scRawPt, _branches);
  utils::book(_tree, _name, "chIso", size, 'F', chIso, _branches);
  utils::book(_tree, _name, "chIsoMax", size, 'F', chIsoMax, _branches);
  utils::book(_tree, _name, "nhIso", size, 'F', nhIso, _branches);
  utils::book(_tree, _name, "phIso", size, 'F', phIso, _branches);
  utils::book(_tree, _name, "chIsoS15", size, 'F', chIsoS15, _branches);
  utils::book(_tree, _name, "nhIsoS15", size, 'F', nhIsoS15, _branches);
  utils::book(_tree, _name, "phIsoS15", size, 'F', phIsoS15, _branches);
  utils::book(_tree, _name, "sieie", size, 'F', sieie, _branches);
  utils::book(_tree, _name, "sipip", size, 'F', sipip, _branches);
  utils::book(_tree, _name, "hOverE", size, 'F', hOverE, _branches);
  utils::book(_tree, _name, "genIso", size, 'F', genIso, _branches);
  utils::book(_tree, _name, "mipEnergy", size, 'F', mipEnergy, _branches);
  utils::book(_tree, _name, "e33", size, 'F', e33, _branches);
  utils::book(_tree, _name, "e4", size, 'F', e4, _branches);
  utils::book(_tree, _name, "eseed", size, 'F', eseed, _branches);
  utils::book(_tree, _name, "emax", size, 'F', emax, _branches);
  utils::book(_tree, _name, "e2nd", size, 'F', e2nd, _branches);
  utils::book(_tree, _name, "r9", size, 'F', r9, _branches);
  utils::book(_tree, _name, "etaWidth", size, 'F', etaWidth, _branches);
  utils::book(_tree, _name, "phiWidth", size, 'F', phiWidth, _branches);
  utils::book(_tree, _name, "time", size, 'F', time, _branches);
  utils::book(_tree, _name, "timeSpan", size, 'F', timeSpan, _branches);
  utils::book(_tree, _name, "loose", size, 'O', loose, _branches);
  utils::book(_tree, _name, "medium", size, 'O', medium, _branches);
  utils::book(_tree, _name, "tight", size, 'O', tight, _branches);
  utils::book(_tree, _name, "highpt", size, 'O', highpt, _branches);
  utils::book(_tree, _name, "isEB", size, 'O', isEB, _branches);
  utils::book(_tree, _name, "pixelVeto", size, 'O', pixelVeto, _branches);
  utils::book(_tree, _name, "csafeVeto", size, 'O', csafeVeto, _branches);
  utils::book(_tree, _name, "triggerMatch", size + TString::Format("[%d]", nPhotonTriggerObjects), 'O', triggerMatch, _branches);
  utils::book(_tree, _name, "superCluster_", size, 'I', superCluster_, _branches);
  utils::book(_tree, _name, "matchedGen_", size, 'I', matchedGen_, _branches);
}

void
panda::Photon::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  Particle::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "scRawPt");
  utils::resetAddress(_tree, _name, "chIso");
  utils::resetAddress(_tree, _name, "chIsoMax");
  utils::resetAddress(_tree, _name, "nhIso");
  utils::resetAddress(_tree, _name, "phIso");
  utils::resetAddress(_tree, _name, "chIsoS15");
  utils::resetAddress(_tree, _name, "nhIsoS15");
  utils::resetAddress(_tree, _name, "phIsoS15");
  utils::resetAddress(_tree, _name, "sieie");
  utils::resetAddress(_tree, _name, "sipip");
  utils::resetAddress(_tree, _name, "hOverE");
  utils::resetAddress(_tree, _name, "genIso");
  utils::resetAddress(_tree, _name, "mipEnergy");
  utils::resetAddress(_tree, _name, "e33");
  utils::resetAddress(_tree, _name, "e4");
  utils::resetAddress(_tree, _name, "eseed");
  utils::resetAddress(_tree, _name, "emax");
  utils::resetAddress(_tree, _name, "e2nd");
  utils::resetAddress(_tree, _name, "r9");
  utils::resetAddress(_tree, _name, "etaWidth");
  utils::resetAddress(_tree, _name, "phiWidth");
  utils::resetAddress(_tree, _name, "time");
  utils::resetAddress(_tree, _name, "timeSpan");
  utils::resetAddress(_tree, _name, "loose");
  utils::resetAddress(_tree, _name, "medium");
  utils::resetAddress(_tree, _name, "tight");
  utils::resetAddress(_tree, _name, "highpt");
  utils::resetAddress(_tree, _name, "isEB");
  utils::resetAddress(_tree, _name, "pixelVeto");
  utils::resetAddress(_tree, _name, "csafeVeto");
  utils::resetAddress(_tree, _name, "triggerMatch");
  utils::resetAddress(_tree, _name, "superCluster_");
  utils::resetAddress(_tree, _name, "matchedGen_");
}

void
panda::Photon::datastore::resizeVectors_(UInt_t _size)
{
  Particle::datastore::resizeVectors_(_size);

}

panda::Photon::Photon(char const* _name/* = ""*/) :
  Particle(new PhotonArray(1, _name)),
  scRawPt(gStore.getData(this).scRawPt[0]),
  chIso(gStore.getData(this).chIso[0]),
  chIsoMax(gStore.getData(this).chIsoMax[0]),
  nhIso(gStore.getData(this).nhIso[0]),
  phIso(gStore.getData(this).phIso[0]),
  chIsoS15(gStore.getData(this).chIsoS15[0]),
  nhIsoS15(gStore.getData(this).nhIsoS15[0]),
  phIsoS15(gStore.getData(this).phIsoS15[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  hOverE(gStore.getData(this).hOverE[0]),
  genIso(gStore.getData(this).genIso[0]),
  mipEnergy(gStore.getData(this).mipEnergy[0]),
  e33(gStore.getData(this).e33[0]),
  e4(gStore.getData(this).e4[0]),
  eseed(gStore.getData(this).eseed[0]),
  emax(gStore.getData(this).emax[0]),
  e2nd(gStore.getData(this).e2nd[0]),
  r9(gStore.getData(this).r9[0]),
  etaWidth(gStore.getData(this).etaWidth[0]),
  phiWidth(gStore.getData(this).phiWidth[0]),
  time(gStore.getData(this).time[0]),
  timeSpan(gStore.getData(this).timeSpan[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  highpt(gStore.getData(this).highpt[0]),
  isEB(gStore.getData(this).isEB[0]),
  pixelVeto(gStore.getData(this).pixelVeto[0]),
  csafeVeto(gStore.getData(this).csafeVeto[0]),
  triggerMatch(gStore.getData(this).triggerMatch[0]),
  superCluster(gStore.getData(this).superClusterContainer_, gStore.getData(this).superCluster_[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
}

panda::Photon::Photon(datastore& _data, UInt_t _idx) :
  Particle(_data, _idx),
  scRawPt(_data.scRawPt[_idx]),
  chIso(_data.chIso[_idx]),
  chIsoMax(_data.chIsoMax[_idx]),
  nhIso(_data.nhIso[_idx]),
  phIso(_data.phIso[_idx]),
  chIsoS15(_data.chIsoS15[_idx]),
  nhIsoS15(_data.nhIsoS15[_idx]),
  phIsoS15(_data.phIsoS15[_idx]),
  sieie(_data.sieie[_idx]),
  sipip(_data.sipip[_idx]),
  hOverE(_data.hOverE[_idx]),
  genIso(_data.genIso[_idx]),
  mipEnergy(_data.mipEnergy[_idx]),
  e33(_data.e33[_idx]),
  e4(_data.e4[_idx]),
  eseed(_data.eseed[_idx]),
  emax(_data.emax[_idx]),
  e2nd(_data.e2nd[_idx]),
  r9(_data.r9[_idx]),
  etaWidth(_data.etaWidth[_idx]),
  phiWidth(_data.phiWidth[_idx]),
  time(_data.time[_idx]),
  timeSpan(_data.timeSpan[_idx]),
  loose(_data.loose[_idx]),
  medium(_data.medium[_idx]),
  tight(_data.tight[_idx]),
  highpt(_data.highpt[_idx]),
  isEB(_data.isEB[_idx]),
  pixelVeto(_data.pixelVeto[_idx]),
  csafeVeto(_data.csafeVeto[_idx]),
  triggerMatch(_data.triggerMatch[_idx]),
  superCluster(_data.superClusterContainer_, _data.superCluster_[_idx]),
  matchedGen(_data.matchedGenContainer_, _data.matchedGen_[_idx])
{
}

panda::Photon::Photon(Photon const& _src) :
  Particle(new PhotonArray(1, gStore.getName(&_src))),
  scRawPt(gStore.getData(this).scRawPt[0]),
  chIso(gStore.getData(this).chIso[0]),
  chIsoMax(gStore.getData(this).chIsoMax[0]),
  nhIso(gStore.getData(this).nhIso[0]),
  phIso(gStore.getData(this).phIso[0]),
  chIsoS15(gStore.getData(this).chIsoS15[0]),
  nhIsoS15(gStore.getData(this).nhIsoS15[0]),
  phIsoS15(gStore.getData(this).phIsoS15[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  hOverE(gStore.getData(this).hOverE[0]),
  genIso(gStore.getData(this).genIso[0]),
  mipEnergy(gStore.getData(this).mipEnergy[0]),
  e33(gStore.getData(this).e33[0]),
  e4(gStore.getData(this).e4[0]),
  eseed(gStore.getData(this).eseed[0]),
  emax(gStore.getData(this).emax[0]),
  e2nd(gStore.getData(this).e2nd[0]),
  r9(gStore.getData(this).r9[0]),
  etaWidth(gStore.getData(this).etaWidth[0]),
  phiWidth(gStore.getData(this).phiWidth[0]),
  time(gStore.getData(this).time[0]),
  timeSpan(gStore.getData(this).timeSpan[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  highpt(gStore.getData(this).highpt[0]),
  isEB(gStore.getData(this).isEB[0]),
  pixelVeto(gStore.getData(this).pixelVeto[0]),
  csafeVeto(gStore.getData(this).csafeVeto[0]),
  triggerMatch(gStore.getData(this).triggerMatch[0]),
  superCluster(gStore.getData(this).superClusterContainer_, gStore.getData(this).superCluster_[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
  Particle::operator=(_src);

  scRawPt = _src.scRawPt;
  chIso = _src.chIso;
  chIsoMax = _src.chIsoMax;
  nhIso = _src.nhIso;
  phIso = _src.phIso;
  chIsoS15 = _src.chIsoS15;
  nhIsoS15 = _src.nhIsoS15;
  phIsoS15 = _src.phIsoS15;
  sieie = _src.sieie;
  sipip = _src.sipip;
  hOverE = _src.hOverE;
  genIso = _src.genIso;
  mipEnergy = _src.mipEnergy;
  e33 = _src.e33;
  e4 = _src.e4;
  eseed = _src.eseed;
  emax = _src.emax;
  e2nd = _src.e2nd;
  r9 = _src.r9;
  etaWidth = _src.etaWidth;
  phiWidth = _src.phiWidth;
  time = _src.time;
  timeSpan = _src.timeSpan;
  loose = _src.loose;
  medium = _src.medium;
  tight = _src.tight;
  highpt = _src.highpt;
  isEB = _src.isEB;
  pixelVeto = _src.pixelVeto;
  csafeVeto = _src.csafeVeto;
  std::memcpy(triggerMatch, _src.triggerMatch, sizeof(Bool_t) * nPhotonTriggerObjects);
  superCluster = _src.superCluster;
  matchedGen = _src.matchedGen;
}

panda::Photon::Photon(ArrayBase* _array) :
  Particle(_array),
  scRawPt(gStore.getData(this).scRawPt[0]),
  chIso(gStore.getData(this).chIso[0]),
  chIsoMax(gStore.getData(this).chIsoMax[0]),
  nhIso(gStore.getData(this).nhIso[0]),
  phIso(gStore.getData(this).phIso[0]),
  chIsoS15(gStore.getData(this).chIsoS15[0]),
  nhIsoS15(gStore.getData(this).nhIsoS15[0]),
  phIsoS15(gStore.getData(this).phIsoS15[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  hOverE(gStore.getData(this).hOverE[0]),
  genIso(gStore.getData(this).genIso[0]),
  mipEnergy(gStore.getData(this).mipEnergy[0]),
  e33(gStore.getData(this).e33[0]),
  e4(gStore.getData(this).e4[0]),
  eseed(gStore.getData(this).eseed[0]),
  emax(gStore.getData(this).emax[0]),
  e2nd(gStore.getData(this).e2nd[0]),
  r9(gStore.getData(this).r9[0]),
  etaWidth(gStore.getData(this).etaWidth[0]),
  phiWidth(gStore.getData(this).phiWidth[0]),
  time(gStore.getData(this).time[0]),
  timeSpan(gStore.getData(this).timeSpan[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  highpt(gStore.getData(this).highpt[0]),
  isEB(gStore.getData(this).isEB[0]),
  pixelVeto(gStore.getData(this).pixelVeto[0]),
  csafeVeto(gStore.getData(this).csafeVeto[0]),
  triggerMatch(gStore.getData(this).triggerMatch[0]),
  superCluster(gStore.getData(this).superClusterContainer_, gStore.getData(this).superCluster_[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
}

panda::Photon::~Photon()
{
  destructor();
  gStore.free(this);
}

void
panda::Photon::destructor()
{
  /* BEGIN CUSTOM Photon.cc.destructor */
  /* END CUSTOM */

  Particle::destructor();
}

panda::Photon&
panda::Photon::operator=(Photon const& _src)
{
  Particle::operator=(_src);

  scRawPt = _src.scRawPt;
  chIso = _src.chIso;
  chIsoMax = _src.chIsoMax;
  nhIso = _src.nhIso;
  phIso = _src.phIso;
  chIsoS15 = _src.chIsoS15;
  nhIsoS15 = _src.nhIsoS15;
  phIsoS15 = _src.phIsoS15;
  sieie = _src.sieie;
  sipip = _src.sipip;
  hOverE = _src.hOverE;
  genIso = _src.genIso;
  mipEnergy = _src.mipEnergy;
  e33 = _src.e33;
  e4 = _src.e4;
  eseed = _src.eseed;
  emax = _src.emax;
  e2nd = _src.e2nd;
  r9 = _src.r9;
  etaWidth = _src.etaWidth;
  phiWidth = _src.phiWidth;
  time = _src.time;
  timeSpan = _src.timeSpan;
  loose = _src.loose;
  medium = _src.medium;
  tight = _src.tight;
  highpt = _src.highpt;
  isEB = _src.isEB;
  pixelVeto = _src.pixelVeto;
  csafeVeto = _src.csafeVeto;
  std::memcpy(triggerMatch, _src.triggerMatch, sizeof(Bool_t) * nPhotonTriggerObjects);
  superCluster = _src.superCluster;
  matchedGen = _src.matchedGen;

  return *this;
}

void
panda::Photon::doSetStatus_(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Particle::doSetStatus_(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "scRawPt", _branches);
  utils::setStatus(_tree, _name, "chIso", _branches);
  utils::setStatus(_tree, _name, "chIsoMax", _branches);
  utils::setStatus(_tree, _name, "nhIso", _branches);
  utils::setStatus(_tree, _name, "phIso", _branches);
  utils::setStatus(_tree, _name, "chIsoS15", _branches);
  utils::setStatus(_tree, _name, "nhIsoS15", _branches);
  utils::setStatus(_tree, _name, "phIsoS15", _branches);
  utils::setStatus(_tree, _name, "sieie", _branches);
  utils::setStatus(_tree, _name, "sipip", _branches);
  utils::setStatus(_tree, _name, "hOverE", _branches);
  utils::setStatus(_tree, _name, "genIso", _branches);
  utils::setStatus(_tree, _name, "mipEnergy", _branches);
  utils::setStatus(_tree, _name, "e33", _branches);
  utils::setStatus(_tree, _name, "e4", _branches);
  utils::setStatus(_tree, _name, "eseed", _branches);
  utils::setStatus(_tree, _name, "emax", _branches);
  utils::setStatus(_tree, _name, "e2nd", _branches);
  utils::setStatus(_tree, _name, "r9", _branches);
  utils::setStatus(_tree, _name, "etaWidth", _branches);
  utils::setStatus(_tree, _name, "phiWidth", _branches);
  utils::setStatus(_tree, _name, "time", _branches);
  utils::setStatus(_tree, _name, "timeSpan", _branches);
  utils::setStatus(_tree, _name, "loose", _branches);
  utils::setStatus(_tree, _name, "medium", _branches);
  utils::setStatus(_tree, _name, "tight", _branches);
  utils::setStatus(_tree, _name, "highpt", _branches);
  utils::setStatus(_tree, _name, "isEB", _branches);
  utils::setStatus(_tree, _name, "pixelVeto", _branches);
  utils::setStatus(_tree, _name, "csafeVeto", _branches);
  utils::setStatus(_tree, _name, "triggerMatch", _branches);
  utils::setStatus(_tree, _name, "superCluster_", _branches);
  utils::setStatus(_tree, _name, "matchedGen_", _branches);
}

panda::utils::BranchList
panda::Photon::doGetStatus_(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Particle::doGetStatus_(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "scRawPt"));
  blist.push_back(utils::getStatus(_tree, _name, "chIso"));
  blist.push_back(utils::getStatus(_tree, _name, "chIsoMax"));
  blist.push_back(utils::getStatus(_tree, _name, "nhIso"));
  blist.push_back(utils::getStatus(_tree, _name, "phIso"));
  blist.push_back(utils::getStatus(_tree, _name, "chIsoS15"));
  blist.push_back(utils::getStatus(_tree, _name, "nhIsoS15"));
  blist.push_back(utils::getStatus(_tree, _name, "phIsoS15"));
  blist.push_back(utils::getStatus(_tree, _name, "sieie"));
  blist.push_back(utils::getStatus(_tree, _name, "sipip"));
  blist.push_back(utils::getStatus(_tree, _name, "hOverE"));
  blist.push_back(utils::getStatus(_tree, _name, "genIso"));
  blist.push_back(utils::getStatus(_tree, _name, "mipEnergy"));
  blist.push_back(utils::getStatus(_tree, _name, "e33"));
  blist.push_back(utils::getStatus(_tree, _name, "e4"));
  blist.push_back(utils::getStatus(_tree, _name, "eseed"));
  blist.push_back(utils::getStatus(_tree, _name, "emax"));
  blist.push_back(utils::getStatus(_tree, _name, "e2nd"));
  blist.push_back(utils::getStatus(_tree, _name, "r9"));
  blist.push_back(utils::getStatus(_tree, _name, "etaWidth"));
  blist.push_back(utils::getStatus(_tree, _name, "phiWidth"));
  blist.push_back(utils::getStatus(_tree, _name, "time"));
  blist.push_back(utils::getStatus(_tree, _name, "timeSpan"));
  blist.push_back(utils::getStatus(_tree, _name, "loose"));
  blist.push_back(utils::getStatus(_tree, _name, "medium"));
  blist.push_back(utils::getStatus(_tree, _name, "tight"));
  blist.push_back(utils::getStatus(_tree, _name, "highpt"));
  blist.push_back(utils::getStatus(_tree, _name, "isEB"));
  blist.push_back(utils::getStatus(_tree, _name, "pixelVeto"));
  blist.push_back(utils::getStatus(_tree, _name, "csafeVeto"));
  blist.push_back(utils::getStatus(_tree, _name, "triggerMatch"));
  blist.push_back(utils::getStatus(_tree, _name, "superCluster_"));
  blist.push_back(utils::getStatus(_tree, _name, "matchedGen_"));

  return blist;
}

void
panda::Photon::doSetAddress_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Particle::doSetAddress_(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "scRawPt", &scRawPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chIso", &chIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chIsoMax", &chIsoMax, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhIso", &nhIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phIso", &phIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chIsoS15", &chIsoS15, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhIsoS15", &nhIsoS15, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phIsoS15", &phIsoS15, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sieie", &sieie, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sipip", &sipip, _branches, _setStatus);
  utils::setAddress(_tree, _name, "hOverE", &hOverE, _branches, _setStatus);
  utils::setAddress(_tree, _name, "genIso", &genIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mipEnergy", &mipEnergy, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e33", &e33, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e4", &e4, _branches, _setStatus);
  utils::setAddress(_tree, _name, "eseed", &eseed, _branches, _setStatus);
  utils::setAddress(_tree, _name, "emax", &emax, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e2nd", &e2nd, _branches, _setStatus);
  utils::setAddress(_tree, _name, "r9", &r9, _branches, _setStatus);
  utils::setAddress(_tree, _name, "etaWidth", &etaWidth, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phiWidth", &phiWidth, _branches, _setStatus);
  utils::setAddress(_tree, _name, "time", &time, _branches, _setStatus);
  utils::setAddress(_tree, _name, "timeSpan", &timeSpan, _branches, _setStatus);
  utils::setAddress(_tree, _name, "loose", &loose, _branches, _setStatus);
  utils::setAddress(_tree, _name, "medium", &medium, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tight", &tight, _branches, _setStatus);
  utils::setAddress(_tree, _name, "highpt", &highpt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "isEB", &isEB, _branches, _setStatus);
  utils::setAddress(_tree, _name, "pixelVeto", &pixelVeto, _branches, _setStatus);
  utils::setAddress(_tree, _name, "csafeVeto", &csafeVeto, _branches, _setStatus);
  utils::setAddress(_tree, _name, "triggerMatch", triggerMatch, _branches, _setStatus);
  utils::setAddress(_tree, _name, "superCluster_", gStore.getData(this).superCluster_, _branches, true);
  utils::setAddress(_tree, _name, "matchedGen_", gStore.getData(this).matchedGen_, _branches, true);
}

void
panda::Photon::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  Particle::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "scRawPt", "", 'F', &scRawPt, _branches);
  utils::book(_tree, _name, "chIso", "", 'F', &chIso, _branches);
  utils::book(_tree, _name, "chIsoMax", "", 'F', &chIsoMax, _branches);
  utils::book(_tree, _name, "nhIso", "", 'F', &nhIso, _branches);
  utils::book(_tree, _name, "phIso", "", 'F', &phIso, _branches);
  utils::book(_tree, _name, "chIsoS15", "", 'F', &chIsoS15, _branches);
  utils::book(_tree, _name, "nhIsoS15", "", 'F', &nhIsoS15, _branches);
  utils::book(_tree, _name, "phIsoS15", "", 'F', &phIsoS15, _branches);
  utils::book(_tree, _name, "sieie", "", 'F', &sieie, _branches);
  utils::book(_tree, _name, "sipip", "", 'F', &sipip, _branches);
  utils::book(_tree, _name, "hOverE", "", 'F', &hOverE, _branches);
  utils::book(_tree, _name, "genIso", "", 'F', &genIso, _branches);
  utils::book(_tree, _name, "mipEnergy", "", 'F', &mipEnergy, _branches);
  utils::book(_tree, _name, "e33", "", 'F', &e33, _branches);
  utils::book(_tree, _name, "e4", "", 'F', &e4, _branches);
  utils::book(_tree, _name, "eseed", "", 'F', &eseed, _branches);
  utils::book(_tree, _name, "emax", "", 'F', &emax, _branches);
  utils::book(_tree, _name, "e2nd", "", 'F', &e2nd, _branches);
  utils::book(_tree, _name, "r9", "", 'F', &r9, _branches);
  utils::book(_tree, _name, "etaWidth", "", 'F', &etaWidth, _branches);
  utils::book(_tree, _name, "phiWidth", "", 'F', &phiWidth, _branches);
  utils::book(_tree, _name, "time", "", 'F', &time, _branches);
  utils::book(_tree, _name, "timeSpan", "", 'F', &timeSpan, _branches);
  utils::book(_tree, _name, "loose", "", 'O', &loose, _branches);
  utils::book(_tree, _name, "medium", "", 'O', &medium, _branches);
  utils::book(_tree, _name, "tight", "", 'O', &tight, _branches);
  utils::book(_tree, _name, "highpt", "", 'O', &highpt, _branches);
  utils::book(_tree, _name, "isEB", "", 'O', &isEB, _branches);
  utils::book(_tree, _name, "pixelVeto", "", 'O', &pixelVeto, _branches);
  utils::book(_tree, _name, "csafeVeto", "", 'O', &csafeVeto, _branches);
  utils::book(_tree, _name, "triggerMatch", TString::Format("[%d]", nPhotonTriggerObjects), 'O', triggerMatch, _branches);
  utils::book(_tree, _name, "superCluster_", "", 'I', gStore.getData(this).superCluster_, _branches);
  utils::book(_tree, _name, "matchedGen_", "", 'I', gStore.getData(this).matchedGen_, _branches);
}

void
panda::Photon::doReleaseTree_(TTree& _tree, TString const& _name)
{
  Particle::doReleaseTree_(_tree, _name);

  utils::resetAddress(_tree, _name, "scRawPt");
  utils::resetAddress(_tree, _name, "chIso");
  utils::resetAddress(_tree, _name, "chIsoMax");
  utils::resetAddress(_tree, _name, "nhIso");
  utils::resetAddress(_tree, _name, "phIso");
  utils::resetAddress(_tree, _name, "chIsoS15");
  utils::resetAddress(_tree, _name, "nhIsoS15");
  utils::resetAddress(_tree, _name, "phIsoS15");
  utils::resetAddress(_tree, _name, "sieie");
  utils::resetAddress(_tree, _name, "sipip");
  utils::resetAddress(_tree, _name, "hOverE");
  utils::resetAddress(_tree, _name, "genIso");
  utils::resetAddress(_tree, _name, "mipEnergy");
  utils::resetAddress(_tree, _name, "e33");
  utils::resetAddress(_tree, _name, "e4");
  utils::resetAddress(_tree, _name, "eseed");
  utils::resetAddress(_tree, _name, "emax");
  utils::resetAddress(_tree, _name, "e2nd");
  utils::resetAddress(_tree, _name, "r9");
  utils::resetAddress(_tree, _name, "etaWidth");
  utils::resetAddress(_tree, _name, "phiWidth");
  utils::resetAddress(_tree, _name, "time");
  utils::resetAddress(_tree, _name, "timeSpan");
  utils::resetAddress(_tree, _name, "loose");
  utils::resetAddress(_tree, _name, "medium");
  utils::resetAddress(_tree, _name, "tight");
  utils::resetAddress(_tree, _name, "highpt");
  utils::resetAddress(_tree, _name, "isEB");
  utils::resetAddress(_tree, _name, "pixelVeto");
  utils::resetAddress(_tree, _name, "csafeVeto");
  utils::resetAddress(_tree, _name, "triggerMatch");
  utils::resetAddress(_tree, _name, "superCluster_");
  utils::resetAddress(_tree, _name, "matchedGen_");
}

void
panda::Photon::doInit_()
{
  Particle::doInit_();

  scRawPt = 0.;
  chIso = 0.;
  chIsoMax = 0.;
  nhIso = 0.;
  phIso = 0.;
  chIsoS15 = 0.;
  nhIsoS15 = 0.;
  phIsoS15 = 0.;
  sieie = 0.;
  sipip = 0.;
  hOverE = 0.;
  genIso = 0.;
  mipEnergy = 0.;
  e33 = 0.;
  e4 = 0.;
  eseed = 0.;
  emax = 0.;
  e2nd = 0.;
  r9 = 0.;
  etaWidth = 0.;
  phiWidth = 0.;
  time = 0.;
  timeSpan = 0.;
  loose = false;
  medium = false;
  tight = false;
  highpt = false;
  isEB = false;
  pixelVeto = false;
  csafeVeto = false;
  for (auto& p0 : triggerMatch) p0 = false;
  superCluster.init();
  matchedGen.init();
}


/* BEGIN CUSTOM Photon.cc.global */
/* END CUSTOM */
