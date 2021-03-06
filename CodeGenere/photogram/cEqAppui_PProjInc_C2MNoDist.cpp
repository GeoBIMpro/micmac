// File Automatically generated by eLiSe
#include "general/all.h"
#include "private/all.h"
#include "cEqAppui_PProjInc_C2MNoDist.h"


cEqAppui_PProjInc_C2MNoDist::cEqAppui_PProjInc_C2MNoDist():
    cElCompiledFonc(2)
{
   AddIntRef (cIncIntervale("Intr",0,3));
   AddIntRef (cIncIntervale("Orient",3,9));
   AddIntRef (cIncIntervale("Tmp_PTer",9,12));
   Close(false);
}



void cEqAppui_PProjInc_C2MNoDist::ComputeVal()
{
   double tmp0_ = mCompCoord[3];
   double tmp1_ = mCompCoord[4];
   double tmp2_ = cos(tmp1_);
   double tmp3_ = mCompCoord[9];
   double tmp4_ = mCompCoord[10];
   double tmp5_ = mCompCoord[11];
   double tmp6_ = sin(tmp0_);
   double tmp7_ = cos(tmp0_);
   double tmp8_ = sin(tmp1_);
   double tmp9_ = mCompCoord[5];
   double tmp10_ = mLocProjI_x*tmp3_;
   double tmp11_ = mLocProjP0_x+tmp10_;
   double tmp12_ = mLocProjJ_x*tmp4_;
   double tmp13_ = tmp11_+tmp12_;
   double tmp14_ = mLocProjK_x/tmp5_;
   double tmp15_ = tmp13_+tmp14_;
   double tmp16_ = mCompCoord[6];
   double tmp17_ = (tmp15_)-tmp16_;
   double tmp18_ = sin(tmp9_);
   double tmp19_ = -(tmp18_);
   double tmp20_ = -(tmp8_);
   double tmp21_ = cos(tmp9_);
   double tmp22_ = mLocProjI_y*tmp3_;
   double tmp23_ = mLocProjP0_y+tmp22_;
   double tmp24_ = mLocProjJ_y*tmp4_;
   double tmp25_ = tmp23_+tmp24_;
   double tmp26_ = mLocProjK_y/tmp5_;
   double tmp27_ = tmp25_+tmp26_;
   double tmp28_ = mCompCoord[7];
   double tmp29_ = (tmp27_)-tmp28_;
   double tmp30_ = mLocProjI_z*tmp3_;
   double tmp31_ = mLocProjP0_z+tmp30_;
   double tmp32_ = mLocProjJ_z*tmp4_;
   double tmp33_ = tmp31_+tmp32_;
   double tmp34_ = mLocProjK_z/tmp5_;
   double tmp35_ = tmp33_+tmp34_;
   double tmp36_ = mCompCoord[8];
   double tmp37_ = (tmp35_)-tmp36_;
   double tmp38_ = mCompCoord[0];
   double tmp39_ = -(tmp6_);
   double tmp40_ = tmp7_*tmp20_;
   double tmp41_ = tmp6_*tmp20_;
   double tmp42_ = tmp39_*tmp19_;
   double tmp43_ = tmp40_*tmp21_;
   double tmp44_ = tmp42_+tmp43_;
   double tmp45_ = (tmp44_)*(tmp17_);
   double tmp46_ = tmp7_*tmp19_;
   double tmp47_ = tmp41_*tmp21_;
   double tmp48_ = tmp46_+tmp47_;
   double tmp49_ = (tmp48_)*(tmp29_);
   double tmp50_ = tmp45_+tmp49_;
   double tmp51_ = tmp2_*tmp21_;
   double tmp52_ = tmp51_*(tmp37_);
   double tmp53_ = tmp50_+tmp52_;

  mVal[0] = (mCompCoord[1]+tmp38_*((tmp7_*tmp2_*(tmp17_)+tmp6_*tmp2_*(tmp29_)+tmp8_*(tmp37_))/(tmp53_)))-mLocXIm;

  mVal[1] = (mCompCoord[2]+tmp38_*(((tmp39_*tmp21_+tmp40_*tmp18_)*(tmp17_)+(tmp7_*tmp21_+tmp41_*tmp18_)*(tmp29_)+tmp2_*tmp18_*(tmp37_))/(tmp53_)))-mLocYIm;

}


void cEqAppui_PProjInc_C2MNoDist::ComputeValDeriv()
{
   double tmp0_ = mCompCoord[3];
   double tmp1_ = mCompCoord[4];
   double tmp2_ = cos(tmp1_);
   double tmp3_ = mCompCoord[9];
   double tmp4_ = mCompCoord[10];
   double tmp5_ = mCompCoord[11];
   double tmp6_ = sin(tmp0_);
   double tmp7_ = cos(tmp0_);
   double tmp8_ = sin(tmp1_);
   double tmp9_ = mCompCoord[5];
   double tmp10_ = mLocProjI_x*tmp3_;
   double tmp11_ = mLocProjP0_x+tmp10_;
   double tmp12_ = mLocProjJ_x*tmp4_;
   double tmp13_ = tmp11_+tmp12_;
   double tmp14_ = mLocProjK_x/tmp5_;
   double tmp15_ = tmp13_+tmp14_;
   double tmp16_ = mCompCoord[6];
   double tmp17_ = (tmp15_)-tmp16_;
   double tmp18_ = sin(tmp9_);
   double tmp19_ = -(tmp18_);
   double tmp20_ = -(tmp8_);
   double tmp21_ = cos(tmp9_);
   double tmp22_ = mLocProjI_y*tmp3_;
   double tmp23_ = mLocProjP0_y+tmp22_;
   double tmp24_ = mLocProjJ_y*tmp4_;
   double tmp25_ = tmp23_+tmp24_;
   double tmp26_ = mLocProjK_y/tmp5_;
   double tmp27_ = tmp25_+tmp26_;
   double tmp28_ = mCompCoord[7];
   double tmp29_ = (tmp27_)-tmp28_;
   double tmp30_ = mLocProjI_z*tmp3_;
   double tmp31_ = mLocProjP0_z+tmp30_;
   double tmp32_ = mLocProjJ_z*tmp4_;
   double tmp33_ = tmp31_+tmp32_;
   double tmp34_ = mLocProjK_z/tmp5_;
   double tmp35_ = tmp33_+tmp34_;
   double tmp36_ = mCompCoord[8];
   double tmp37_ = (tmp35_)-tmp36_;
   double tmp38_ = tmp7_*tmp2_;
   double tmp39_ = tmp38_*(tmp17_);
   double tmp40_ = tmp6_*tmp2_;
   double tmp41_ = tmp40_*(tmp29_);
   double tmp42_ = tmp39_+tmp41_;
   double tmp43_ = tmp8_*(tmp37_);
   double tmp44_ = tmp42_+tmp43_;
   double tmp45_ = -(tmp6_);
   double tmp46_ = tmp45_*tmp19_;
   double tmp47_ = tmp7_*tmp20_;
   double tmp48_ = tmp47_*tmp21_;
   double tmp49_ = tmp46_+tmp48_;
   double tmp50_ = (tmp49_)*(tmp17_);
   double tmp51_ = tmp7_*tmp19_;
   double tmp52_ = tmp6_*tmp20_;
   double tmp53_ = tmp52_*tmp21_;
   double tmp54_ = tmp51_+tmp53_;
   double tmp55_ = (tmp54_)*(tmp29_);
   double tmp56_ = tmp50_+tmp55_;
   double tmp57_ = tmp2_*tmp21_;
   double tmp58_ = tmp57_*(tmp37_);
   double tmp59_ = tmp56_+tmp58_;
   double tmp60_ = (tmp44_)/(tmp59_);
   double tmp61_ = -(1);
   double tmp62_ = tmp61_*tmp6_;
   double tmp63_ = mCompCoord[0];
   double tmp64_ = tmp61_*tmp8_;
   double tmp65_ = -(tmp2_);
   double tmp66_ = ElSquare(tmp59_);
   double tmp67_ = -(tmp21_);
   double tmp68_ = tmp61_*tmp18_;
   double tmp69_ = ElSquare(tmp5_);
   double tmp70_ = -(mLocProjK_x);
   double tmp71_ = tmp70_/tmp69_;
   double tmp72_ = -(mLocProjK_y);
   double tmp73_ = tmp72_/tmp69_;
   double tmp74_ = -(mLocProjK_z);
   double tmp75_ = tmp74_/tmp69_;
   double tmp76_ = tmp45_*tmp21_;
   double tmp77_ = tmp47_*tmp18_;
   double tmp78_ = tmp76_+tmp77_;
   double tmp79_ = (tmp78_)*(tmp17_);
   double tmp80_ = tmp7_*tmp21_;
   double tmp81_ = tmp52_*tmp18_;
   double tmp82_ = tmp80_+tmp81_;
   double tmp83_ = (tmp82_)*(tmp29_);
   double tmp84_ = tmp79_+tmp83_;
   double tmp85_ = tmp2_*tmp18_;
   double tmp86_ = tmp85_*(tmp37_);
   double tmp87_ = tmp84_+tmp86_;
   double tmp88_ = (tmp87_)/(tmp59_);
   double tmp89_ = -(tmp7_);
   double tmp90_ = tmp62_*tmp20_;
   double tmp91_ = tmp89_*tmp19_;
   double tmp92_ = tmp90_*tmp21_;
   double tmp93_ = tmp91_+tmp92_;
   double tmp94_ = (tmp93_)*(tmp17_);
   double tmp95_ = tmp62_*tmp19_;
   double tmp96_ = tmp95_+tmp48_;
   double tmp97_ = (tmp96_)*(tmp29_);
   double tmp98_ = tmp94_+tmp97_;
   double tmp99_ = tmp65_*tmp7_;
   double tmp100_ = tmp65_*tmp6_;
   double tmp101_ = tmp99_*tmp21_;
   double tmp102_ = tmp101_*(tmp17_);
   double tmp103_ = tmp100_*tmp21_;
   double tmp104_ = tmp103_*(tmp29_);
   double tmp105_ = tmp102_+tmp104_;
   double tmp106_ = tmp64_*tmp21_;
   double tmp107_ = tmp106_*(tmp37_);
   double tmp108_ = tmp105_+tmp107_;
   double tmp109_ = tmp67_*tmp45_;
   double tmp110_ = tmp68_*tmp47_;
   double tmp111_ = tmp109_+tmp110_;
   double tmp112_ = (tmp111_)*(tmp17_);
   double tmp113_ = tmp67_*tmp7_;
   double tmp114_ = tmp68_*tmp52_;
   double tmp115_ = tmp113_+tmp114_;
   double tmp116_ = (tmp115_)*(tmp29_);
   double tmp117_ = tmp112_+tmp116_;
   double tmp118_ = tmp68_*tmp2_;
   double tmp119_ = tmp118_*(tmp37_);
   double tmp120_ = tmp117_+tmp119_;
   double tmp121_ = tmp61_*(tmp49_);
   double tmp122_ = tmp61_*(tmp54_);
   double tmp123_ = tmp61_*tmp57_;
   double tmp124_ = mLocProjI_x*(tmp49_);
   double tmp125_ = mLocProjI_y*(tmp54_);
   double tmp126_ = tmp124_+tmp125_;
   double tmp127_ = mLocProjI_z*tmp57_;
   double tmp128_ = tmp126_+tmp127_;
   double tmp129_ = mLocProjJ_x*(tmp49_);
   double tmp130_ = mLocProjJ_y*(tmp54_);
   double tmp131_ = tmp129_+tmp130_;
   double tmp132_ = mLocProjJ_z*tmp57_;
   double tmp133_ = tmp131_+tmp132_;
   double tmp134_ = (tmp71_)*(tmp49_);
   double tmp135_ = (tmp73_)*(tmp54_);
   double tmp136_ = tmp134_+tmp135_;
   double tmp137_ = (tmp75_)*tmp57_;
   double tmp138_ = tmp136_+tmp137_;

  mVal[0] = (mCompCoord[1]+tmp63_*(tmp60_))-mLocXIm;

  mCompDer[0][0] = tmp60_;
  mCompDer[0][1] = 1;
  mCompDer[0][2] = 0;
  mCompDer[0][3] = (((tmp62_*tmp2_*(tmp17_)+tmp38_*(tmp29_))*(tmp59_)-(tmp44_)*(tmp98_))/tmp66_)*tmp63_;
  mCompDer[0][4] = (((tmp64_*tmp7_*(tmp17_)+tmp64_*tmp6_*(tmp29_)+tmp2_*(tmp37_))*(tmp59_)-(tmp44_)*(tmp108_))/tmp66_)*tmp63_;
  mCompDer[0][5] = (-((tmp44_)*(tmp120_))/tmp66_)*tmp63_;
  mCompDer[0][6] = ((tmp61_*tmp38_*(tmp59_)-(tmp44_)*tmp121_)/tmp66_)*tmp63_;
  mCompDer[0][7] = ((tmp61_*tmp40_*(tmp59_)-(tmp44_)*tmp122_)/tmp66_)*tmp63_;
  mCompDer[0][8] = ((tmp64_*(tmp59_)-(tmp44_)*tmp123_)/tmp66_)*tmp63_;
  mCompDer[0][9] = (((mLocProjI_x*tmp38_+mLocProjI_y*tmp40_+mLocProjI_z*tmp8_)*(tmp59_)-(tmp44_)*(tmp128_))/tmp66_)*tmp63_;
  mCompDer[0][10] = (((mLocProjJ_x*tmp38_+mLocProjJ_y*tmp40_+mLocProjJ_z*tmp8_)*(tmp59_)-(tmp44_)*(tmp133_))/tmp66_)*tmp63_;
  mCompDer[0][11] = ((((tmp71_)*tmp38_+(tmp73_)*tmp40_+(tmp75_)*tmp8_)*(tmp59_)-(tmp44_)*(tmp138_))/tmp66_)*tmp63_;
  mVal[1] = (mCompCoord[2]+tmp63_*(tmp88_))-mLocYIm;

  mCompDer[1][0] = tmp88_;
  mCompDer[1][1] = 0;
  mCompDer[1][2] = 1;
  mCompDer[1][3] = ((((tmp89_*tmp21_+tmp90_*tmp18_)*(tmp17_)+(tmp62_*tmp21_+tmp77_)*(tmp29_))*(tmp59_)-(tmp87_)*(tmp98_))/tmp66_)*tmp63_;
  mCompDer[1][4] = (((tmp99_*tmp18_*(tmp17_)+tmp100_*tmp18_*(tmp29_)+tmp64_*tmp18_*(tmp37_))*(tmp59_)-(tmp87_)*(tmp108_))/tmp66_)*tmp63_;
  mCompDer[1][5] = ((((tmp68_*tmp45_+tmp21_*tmp47_)*(tmp17_)+(tmp68_*tmp7_+tmp21_*tmp52_)*(tmp29_)+tmp21_*tmp2_*(tmp37_))*(tmp59_)-(tmp87_)*(tmp120_))/tmp66_)*tmp63_;
  mCompDer[1][6] = ((tmp61_*(tmp78_)*(tmp59_)-(tmp87_)*tmp121_)/tmp66_)*tmp63_;
  mCompDer[1][7] = ((tmp61_*(tmp82_)*(tmp59_)-(tmp87_)*tmp122_)/tmp66_)*tmp63_;
  mCompDer[1][8] = ((tmp61_*tmp85_*(tmp59_)-(tmp87_)*tmp123_)/tmp66_)*tmp63_;
  mCompDer[1][9] = (((mLocProjI_x*(tmp78_)+mLocProjI_y*(tmp82_)+mLocProjI_z*tmp85_)*(tmp59_)-(tmp87_)*(tmp128_))/tmp66_)*tmp63_;
  mCompDer[1][10] = (((mLocProjJ_x*(tmp78_)+mLocProjJ_y*(tmp82_)+mLocProjJ_z*tmp85_)*(tmp59_)-(tmp87_)*(tmp133_))/tmp66_)*tmp63_;
  mCompDer[1][11] = ((((tmp71_)*(tmp78_)+(tmp73_)*(tmp82_)+(tmp75_)*tmp85_)*(tmp59_)-(tmp87_)*(tmp138_))/tmp66_)*tmp63_;
}


void cEqAppui_PProjInc_C2MNoDist::ComputeValDerivHessian()
{
  ELISE_ASSERT(false,"Foncteur cEqAppui_PProjInc_C2MNoDist Has no Der Sec");
}

void cEqAppui_PProjInc_C2MNoDist::SetProjI_x(double aVal){ mLocProjI_x = aVal;}
void cEqAppui_PProjInc_C2MNoDist::SetProjI_y(double aVal){ mLocProjI_y = aVal;}
void cEqAppui_PProjInc_C2MNoDist::SetProjI_z(double aVal){ mLocProjI_z = aVal;}
void cEqAppui_PProjInc_C2MNoDist::SetProjJ_x(double aVal){ mLocProjJ_x = aVal;}
void cEqAppui_PProjInc_C2MNoDist::SetProjJ_y(double aVal){ mLocProjJ_y = aVal;}
void cEqAppui_PProjInc_C2MNoDist::SetProjJ_z(double aVal){ mLocProjJ_z = aVal;}
void cEqAppui_PProjInc_C2MNoDist::SetProjK_x(double aVal){ mLocProjK_x = aVal;}
void cEqAppui_PProjInc_C2MNoDist::SetProjK_y(double aVal){ mLocProjK_y = aVal;}
void cEqAppui_PProjInc_C2MNoDist::SetProjK_z(double aVal){ mLocProjK_z = aVal;}
void cEqAppui_PProjInc_C2MNoDist::SetProjP0_x(double aVal){ mLocProjP0_x = aVal;}
void cEqAppui_PProjInc_C2MNoDist::SetProjP0_y(double aVal){ mLocProjP0_y = aVal;}
void cEqAppui_PProjInc_C2MNoDist::SetProjP0_z(double aVal){ mLocProjP0_z = aVal;}
void cEqAppui_PProjInc_C2MNoDist::SetXIm(double aVal){ mLocXIm = aVal;}
void cEqAppui_PProjInc_C2MNoDist::SetYIm(double aVal){ mLocYIm = aVal;}



double * cEqAppui_PProjInc_C2MNoDist::AdrVarLocFromString(const std::string & aName)
{
   if (aName == "ProjI_x") return & mLocProjI_x;
   if (aName == "ProjI_y") return & mLocProjI_y;
   if (aName == "ProjI_z") return & mLocProjI_z;
   if (aName == "ProjJ_x") return & mLocProjJ_x;
   if (aName == "ProjJ_y") return & mLocProjJ_y;
   if (aName == "ProjJ_z") return & mLocProjJ_z;
   if (aName == "ProjK_x") return & mLocProjK_x;
   if (aName == "ProjK_y") return & mLocProjK_y;
   if (aName == "ProjK_z") return & mLocProjK_z;
   if (aName == "ProjP0_x") return & mLocProjP0_x;
   if (aName == "ProjP0_y") return & mLocProjP0_y;
   if (aName == "ProjP0_z") return & mLocProjP0_z;
   if (aName == "XIm") return & mLocXIm;
   if (aName == "YIm") return & mLocYIm;
   return 0;
}


cElCompiledFonc::cAutoAddEntry cEqAppui_PProjInc_C2MNoDist::mTheAuto("cEqAppui_PProjInc_C2MNoDist",cEqAppui_PProjInc_C2MNoDist::Alloc);


cElCompiledFonc *  cEqAppui_PProjInc_C2MNoDist::Alloc()
{  return new cEqAppui_PProjInc_C2MNoDist();
}


