/*
 * Generated by Bluespec Compiler, version 2016.07.beta1 (build 34806, 2016-07-05)
 * 
 * On Sat Mar  3 13:02:55 PST 2018
 * 
 */

/* Generation options: keep-fires */
#ifndef __mkTbGCD_h__
#define __mkTbGCD_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkTbGCD module */
class MOD_mkTbGCD : public Module {
 
 /* Clock handles */
 private:
  tClock __clk_handle_0;
 
 /* Clock gate handles */
 public:
  tUInt8 *clk_gate[0];
 
 /* Instantiation parameters */
 public:
 
 /* Module state */
 public:
  MOD_Reg<tUInt8> INST_c1;
  MOD_Reg<tUInt8> INST_c2;
  MOD_Reg<tUInt8> INST_gcd_bz;
  MOD_Reg<tUInt32> INST_gcd_x;
  MOD_Reg<tUInt32> INST_gcd_y;
  MOD_Reg<tUInt32> INST_state;
 
 /* Constructor */
 public:
  MOD_mkTbGCD(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
 
 /* Publicly accessible definitions */
 public:
  tUInt8 DEF_WILL_FIRE_RL_terminate;
  tUInt8 DEF_CAN_FIRE_RL_terminate;
  tUInt8 DEF_WILL_FIRE_RL_bounce;
  tUInt8 DEF_CAN_FIRE_RL_bounce;
  tUInt8 DEF_WILL_FIRE_RL_resp;
  tUInt8 DEF_CAN_FIRE_RL_resp;
  tUInt8 DEF_WILL_FIRE_RL_req;
  tUInt8 DEF_CAN_FIRE_RL_req;
  tUInt8 DEF_WILL_FIRE_RL_init;
  tUInt8 DEF_CAN_FIRE_RL_init;
  tUInt8 DEF_WILL_FIRE_RL_gcd_subtract;
  tUInt8 DEF_CAN_FIRE_RL_gcd_subtract;
  tUInt8 DEF_gcd_bz__h760;
  tUInt8 DEF_b__h566;
  tUInt8 DEF_NOT_gcd_bz___d13;
 
 /* Local definitions */
 private:
  tUInt8 DEF_b__h563;
  tUInt32 DEF_b__h293;
  tUInt32 DEF_b__h292;
  tUInt8 DEF_gcd_x_EQ_0___d8;
 
 /* Rules */
 public:
  void RL_gcd_subtract();
  void RL_init();
  void RL_req();
  void RL_resp();
  void RL_bounce();
  void RL_terminate();
 
 /* Methods */
 public:
 
 /* Reset routines */
 public:
  void reset_RST_N(tUInt8 ARG_rst_in);
 
 /* Static handles to reset routines */
 public:
 
 /* Pointers to reset fns in parent module for asserting output resets */
 private:
 
 /* Functions for the parent module to register its reset fns */
 public:
 
 /* Functions to set the elaborated clock id */
 public:
  void set_clk_0(char const *s);
 
 /* State dumping routine */
 public:
  void dump_state(unsigned int indent);
 
 /* VCD dumping routines */
 public:
  unsigned int dump_VCD_defs(unsigned int levels);
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTbGCD &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkTbGCD &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkTbGCD &backing);
};

#endif /* ifndef __mkTbGCD_h__ */
