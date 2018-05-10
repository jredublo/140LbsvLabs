/*
 * Generated by Bluespec Compiler, version 2016.07.beta1 (build 34806, 2016-07-05)
 * 
 * On Sat Mar 10 14:17:59 PST 2018
 * 
 */

/* Generation options: keep-fires */
#ifndef __mkTop_h__
#define __mkTop_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"
#include "mkAdder.h"


/* Class declaration for the mkTop module */
class MOD_mkTop : public Module {
 
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
  MOD_Fifo<tUWide> INST_adderRequestFIFO;
  MOD_Fifo<tUInt64> INST_adderResponseFIFO;
  MOD_Reg<tUInt32> INST_countGCDOpers;
  MOD_Reg<tUInt32> INST_countIntOpers;
  MOD_Fifo<tUWide> INST_gcdRequestFIFO;
  MOD_Fifo<tUInt64> INST_gcdResponseFIFO;
  MOD_Reg<tUInt8> INST_gcd_input_valid;
  MOD_Reg<tUInt8> INST_gcd_output_valid;
  MOD_Reg<tUInt32> INST_gcd_x;
  MOD_Reg<tUInt32> INST_gcd_y;
  MOD_Fifo<tUWide> INST_inputFIFO;
  MOD_mkAdder INST_intAdder;
  MOD_Fifo<tUInt64> INST_outputFIFO;
 
 /* Constructor */
 public:
  MOD_mkTop(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
  tUInt8 PORT_EN_request;
  tUInt8 PORT_EN_response;
  tUWide PORT_request_req;
  tUInt8 PORT_RDY_request;
  tUInt64 PORT_response;
  tUInt8 PORT_RDY_response;
  tUInt32 PORT_getCounts;
  tUInt8 PORT_RDY_getCounts;
 
 /* Publicly accessible definitions */
 public:
  tUInt8 DEF_WILL_FIRE_response;
  tUInt8 DEF_WILL_FIRE_request;
  tUInt8 DEF_WILL_FIRE_RL_seven;
  tUInt8 DEF_CAN_FIRE_RL_seven;
  tUInt8 DEF_WILL_FIRE_RL_six;
  tUInt8 DEF_CAN_FIRE_RL_six;
  tUInt8 DEF_WILL_FIRE_RL_five;
  tUInt8 DEF_CAN_FIRE_RL_five;
  tUInt8 DEF_WILL_FIRE_RL_four;
  tUInt8 DEF_CAN_FIRE_RL_four;
  tUInt8 DEF_WILL_FIRE_RL_three;
  tUInt8 DEF_CAN_FIRE_RL_three;
  tUInt8 DEF_WILL_FIRE_RL_two;
  tUInt8 DEF_CAN_FIRE_RL_two;
  tUInt8 DEF_WILL_FIRE_RL_oneb;
  tUInt8 DEF_CAN_FIRE_RL_oneb;
  tUInt8 DEF_WILL_FIRE_RL_one;
  tUInt8 DEF_CAN_FIRE_RL_one;
  tUInt8 DEF_WILL_FIRE_RL_gcd_stop;
  tUInt8 DEF_CAN_FIRE_RL_gcd_stop;
  tUInt8 DEF_WILL_FIRE_RL_gcd_subtract;
  tUInt8 DEF_CAN_FIRE_RL_gcd_subtract;
  tUInt8 DEF_WILL_FIRE_RL_gcd_swap;
  tUInt8 DEF_CAN_FIRE_RL_gcd_swap;
  tUInt8 DEF_CAN_FIRE_getCounts;
  tUInt8 DEF_CAN_FIRE_response;
  tUInt8 DEF_CAN_FIRE_request;
  tUWide DEF_inputFIFO_first____d19;
  tUInt32 DEF_finalR_res__h1412;
  tUInt32 DEF_finalR_res__h1416;
  tUInt8 DEF_gcd_x_EQ_0___d6;
 
 /* Local definitions */
 private:
  tUWide DEF_gcdRequestFIFO_first____d38;
  tUWide DEF_adderRequestFIFO_first____d33;
  tUInt32 DEF_x__h1638;
  tUInt32 DEF_x__h1635;
 
 /* Rules */
 public:
  void RL_gcd_swap();
  void RL_gcd_subtract();
  void RL_gcd_stop();
  void RL_one();
  void RL_oneb();
  void RL_two();
  void RL_three();
  void RL_four();
  void RL_five();
  void RL_six();
  void RL_seven();
 
 /* Methods */
 public:
  void METH_request(tUWide ARG_request_req);
  tUInt8 METH_RDY_request();
  tUInt64 METH_response();
  tUInt8 METH_RDY_response();
  tUInt32 METH_getCounts();
  tUInt8 METH_RDY_getCounts();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTop &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkTop &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkTop &backing);
  void vcd_submodules(tVCDDumpType dt, unsigned int levels, MOD_mkTop &backing);
};

#endif /* ifndef __mkTop_h__ */
