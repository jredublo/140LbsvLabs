/*
 * Generated by Bluespec Compiler, version 2016.07.beta1 (build 34806, 2016-07-05)
 * 
 * On Sat Mar 10 11:14:12 PST 2018
 * 
 */

/* Generation options: keep-fires */
#ifndef __mkTbAdder_h__
#define __mkTbAdder_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"
#include "mkAdder.h"


/* Class declaration for the mkTbAdder module */
class MOD_mkTbAdder : public Module {
 
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
  MOD_mkAdder INST_adder;
  MOD_Reg<tUInt8> INST_state;
  MOD_Reg<tUInt8> INST_state2;
 
 /* Constructor */
 public:
  MOD_mkTbAdder(tSimStateHdl simHdl, char const *name, Module *parent);
 
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
  tUInt8 DEF_WILL_FIRE_RL_r_recv_adder2;
  tUInt8 DEF_CAN_FIRE_RL_r_recv_adder2;
  tUInt8 DEF_WILL_FIRE_RL_r_recv_adder;
  tUInt8 DEF_CAN_FIRE_RL_r_recv_adder;
  tUInt8 DEF_WILL_FIRE_RL_r_send_adder2;
  tUInt8 DEF_CAN_FIRE_RL_r_send_adder2;
  tUInt8 DEF_WILL_FIRE_RL_r_send_adder;
  tUInt8 DEF_CAN_FIRE_RL_r_send_adder;
 
 /* Local definitions */
 private:
  tUInt32 DEF_signed_0___d5;
  tUInt32 DEF_x__h503;
 
 /* Rules */
 public:
  void RL_r_send_adder();
  void RL_r_send_adder2();
  void RL_r_recv_adder();
  void RL_r_recv_adder2();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTbAdder &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkTbAdder &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkTbAdder &backing);
  void vcd_submodules(tVCDDumpType dt, unsigned int levels, MOD_mkTbAdder &backing);
};

#endif /* ifndef __mkTbAdder_h__ */