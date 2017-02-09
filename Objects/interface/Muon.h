#ifndef PandaTree_Objects_Muon_h
#define PandaTree_Objects_Muon_h
#include "Constants.h"
#include "Lepton.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class Muon : public Lepton {
  public:
    struct datastore : public Lepton::datastore {
      datastore() : Lepton::datastore() {}
      ~datastore() { deallocate(); }

      /* Particle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      /* Lepton
      Short_t* q{0};
      Bool_t* loose{0};
      Bool_t* medium{0};
      Bool_t* tight{0};
      Float_t* chIso{0};
      Float_t* nhIso{0};
      Float_t* phIso{0};
      Float_t* puIso{0};
      ContainerBase const* matchedGenContainer_{0};
      Int_t* matchedGen_{0};
      */
      Bool_t (*triggerMatch)[nMuonTriggerObjects]{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      utils::BranchList getStatus(TTree&, TString const&) const override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Array<Muon> array_type;
    typedef Collection<Muon> collection_type;

    typedef Lepton base_type;

    Muon(char const* name = "");
    Muon(Muon const&);
    Muon(datastore&, UInt_t idx);
    ~Muon();
    Muon& operator=(Muon const&);


    double m() const override { return 1.05658e-2; }
    double combIso() const override { return chIso + std::max(nhIso + phIso - 0.5 * puIso, 0.); }

    /* Particle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    /* Lepton
    Short_t& q;
    Bool_t& loose;
    Bool_t& medium;
    Bool_t& tight;
    Float_t& chIso;
    Float_t& nhIso;
    Float_t& phIso;
    Float_t& puIso;
    Ref<GenParticle> matchedGen;
    */
    Bool_t (&triggerMatch)[nMuonTriggerObjects];

    /* BEGIN CUSTOM Muon.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    Muon(ArrayBase*);

    void doSetStatus_(TTree&, TString const&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&, TString const&) const override;
    void doSetAddress_(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doReleaseTree_(TTree&, TString const&) override;
    void doInit_() override;
  };

  typedef Muon::array_type MuonArray;
  typedef Muon::collection_type MuonCollection;
  typedef Ref<Muon> MuonRef;
  typedef RefVector<Muon> MuonRefVector;

  /* BEGIN CUSTOM Muon.h.global */
  /* END CUSTOM */

}

#endif
