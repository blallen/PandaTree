#ifndef PandaTree_Objects_Lepton_h
#define PandaTree_Objects_Lepton_h
#include "Constants.h"
#include "Particle.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"
#include "GenParticle.h"

namespace panda {

  class Lepton : public Particle {
  public:
    struct datastore : public Particle::datastore {
      datastore() : Particle::datastore() {}
      ~datastore() { deallocate(); }

      /* Particle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      Char_t* charge{0};
      Bool_t* loose{0};
      Bool_t* medium{0};
      Bool_t* tight{0};
      Float_t* chIso{0};
      Float_t* nhIso{0};
      Float_t* phIso{0};
      Float_t* puIso{0};
      ContainerBase const* matchedGenContainer_{0};
      Int_t* matchedGen_{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      utils::BranchList getStatus(TTree&, TString const&) const override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Array<Lepton> array_type;
    typedef Collection<Lepton> collection_type;

    typedef Particle base_type;

    Lepton(char const* name = "");
    Lepton(Lepton const&);
    Lepton(datastore&, UInt_t idx);
    ~Lepton();
    Lepton& operator=(Lepton const&);


    virtual double combIso() const { return 0.; }

    /* Particle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    Char_t& charge;
    Bool_t& loose;
    Bool_t& medium;
    Bool_t& tight;
    Float_t& chIso;
    Float_t& nhIso;
    Float_t& phIso;
    Float_t& puIso;
    Ref<GenParticle> matchedGen;

    /* BEGIN CUSTOM Lepton.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    Lepton(ArrayBase*);

    void doSetStatus_(TTree&, TString const&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&, TString const&) const override;
    void doSetAddress_(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doReleaseTree_(TTree&, TString const&) override;
    void doInit_() override;
  };

  typedef Lepton::array_type LeptonArray;
  typedef Lepton::collection_type LeptonCollection;
  typedef Ref<Lepton> LeptonRef;
  typedef RefVector<Lepton> LeptonRefVector;

  /* BEGIN CUSTOM Lepton.h.global */
  /* END CUSTOM */

}

#endif
