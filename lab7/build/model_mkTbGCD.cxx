/*
 * Generated by Bluespec Compiler, version 2016.07.beta1 (build 34806, 2016-07-05)
 * 
 * On Sat Mar 10 11:16:13 PST 2018
 * 
 */
#include "bluesim_primitives.h"
#include "model_mkTbGCD.h"

#include <cstdlib>
#include <time.h>
#include "bluesim_kernel_api.h"
#include "bs_vcd.h"
#include "bs_reset.h"


/* Constructor */
MODEL_mkTbGCD::MODEL_mkTbGCD()
{
  mkTbGCD_instance = NULL;
}

/* Function for creating a new model */
void * new_MODEL_mkTbGCD()
{
  MODEL_mkTbGCD *model = new MODEL_mkTbGCD();
  return (void *)(model);
}

/* Schedule functions */

static void schedule_posedge_CLK(tSimStateHdl simHdl, void *instance_ptr)
       {
	 MOD_mkTbGCD &INST_top = *((MOD_mkTbGCD *)(instance_ptr));
	 tUInt8 DEF_INST_top_DEF_gcd_input_valid_AND_NOT_gcd_output_valid___d4;
	 tUInt8 DEF_INST_top_DEF_gcd_x_ULT_gcd_y___d10;
	 tUInt8 DEF_INST_top_DEF_gcd_input_valid_AND_NOT_gcd_output_valid_AND_N_ETC___d8;
	 tUInt8 DEF_INST_top_DEF_NOT_gcd_output_valid___d3;
	 tUInt8 DEF_INST_top_DEF_NOT_gcd_input_valid_6_AND_NOT_gcd_output_valid___d17;
	 tUInt8 DEF_INST_top_DEF_gcd_input_valid__h182;
	 tUInt8 DEF_INST_top_DEF_gcd_output_valid__h184;
	 tUInt8 DEF_INST_top_DEF_x__h488;
	 tUInt8 DEF_INST_top_DEF_x__h850;
	 INST_top.DEF_finalR_res__h688 = INST_top.INST_gcd_x.METH_read();
	 DEF_INST_top_DEF_gcd_output_valid__h184 = INST_top.INST_gcd_output_valid.METH_read();
	 DEF_INST_top_DEF_gcd_input_valid__h182 = INST_top.INST_gcd_input_valid.METH_read();
	 INST_top.DEF_gcd_x_EQ_0___d6 = (INST_top.DEF_finalR_res__h688) == 0u;
	 DEF_INST_top_DEF_NOT_gcd_output_valid___d3 = !DEF_INST_top_DEF_gcd_output_valid__h184;
	 DEF_INST_top_DEF_gcd_input_valid_AND_NOT_gcd_output_valid___d4 = DEF_INST_top_DEF_gcd_input_valid__h182 && DEF_INST_top_DEF_NOT_gcd_output_valid___d3;
	 INST_top.DEF_CAN_FIRE_RL_gcd_stop = DEF_INST_top_DEF_gcd_input_valid_AND_NOT_gcd_output_valid___d4 && INST_top.DEF_gcd_x_EQ_0___d6;
	 INST_top.DEF_WILL_FIRE_RL_gcd_stop = INST_top.DEF_CAN_FIRE_RL_gcd_stop;
	 INST_top.DEF_finalR_res__h684 = INST_top.INST_gcd_y.METH_read();
	 DEF_INST_top_DEF_gcd_x_ULT_gcd_y___d10 = (INST_top.DEF_finalR_res__h688) < (INST_top.DEF_finalR_res__h684);
	 DEF_INST_top_DEF_gcd_input_valid_AND_NOT_gcd_output_valid_AND_N_ETC___d8 = DEF_INST_top_DEF_gcd_input_valid_AND_NOT_gcd_output_valid___d4 && !(INST_top.DEF_gcd_x_EQ_0___d6);
	 INST_top.DEF_CAN_FIRE_RL_gcd_subtract = DEF_INST_top_DEF_gcd_input_valid_AND_NOT_gcd_output_valid_AND_N_ETC___d8 && !DEF_INST_top_DEF_gcd_x_ULT_gcd_y___d10;
	 INST_top.DEF_WILL_FIRE_RL_gcd_subtract = INST_top.DEF_CAN_FIRE_RL_gcd_subtract;
	 INST_top.DEF_CAN_FIRE_RL_gcd_swap = DEF_INST_top_DEF_gcd_input_valid_AND_NOT_gcd_output_valid_AND_N_ETC___d8 && DEF_INST_top_DEF_gcd_x_ULT_gcd_y___d10;
	 INST_top.DEF_WILL_FIRE_RL_gcd_swap = INST_top.DEF_CAN_FIRE_RL_gcd_swap;
	 DEF_INST_top_DEF_x__h850 = INST_top.INST_state2.METH_read();
	 INST_top.DEF_CAN_FIRE_RL_r_recv_gcd = DEF_INST_top_DEF_gcd_output_valid__h184 && DEF_INST_top_DEF_x__h850 == (tUInt8)0u;
	 INST_top.DEF_WILL_FIRE_RL_r_recv_gcd = INST_top.DEF_CAN_FIRE_RL_r_recv_gcd;
	 INST_top.DEF_CAN_FIRE_RL_r_recv_gcd2 = DEF_INST_top_DEF_gcd_output_valid__h184 && DEF_INST_top_DEF_x__h850 == (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_r_recv_gcd2 = INST_top.DEF_CAN_FIRE_RL_r_recv_gcd2;
	 DEF_INST_top_DEF_x__h488 = INST_top.INST_state.METH_read();
	 DEF_INST_top_DEF_NOT_gcd_input_valid_6_AND_NOT_gcd_output_valid___d17 = !DEF_INST_top_DEF_gcd_input_valid__h182 && DEF_INST_top_DEF_NOT_gcd_output_valid___d3;
	 INST_top.DEF_CAN_FIRE_RL_r_send_gcd2 = DEF_INST_top_DEF_NOT_gcd_input_valid_6_AND_NOT_gcd_output_valid___d17 && DEF_INST_top_DEF_x__h488 == (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_r_send_gcd2 = INST_top.DEF_CAN_FIRE_RL_r_send_gcd2;
	 INST_top.DEF_CAN_FIRE_RL_r_send_gcd = DEF_INST_top_DEF_NOT_gcd_input_valid_6_AND_NOT_gcd_output_valid___d17 && DEF_INST_top_DEF_x__h488 == (tUInt8)0u;
	 INST_top.DEF_WILL_FIRE_RL_r_send_gcd = INST_top.DEF_CAN_FIRE_RL_r_send_gcd;
	 if (INST_top.DEF_WILL_FIRE_RL_gcd_stop)
	   INST_top.RL_gcd_stop();
	 if (INST_top.DEF_WILL_FIRE_RL_gcd_subtract)
	   INST_top.RL_gcd_subtract();
	 if (INST_top.DEF_WILL_FIRE_RL_gcd_swap)
	   INST_top.RL_gcd_swap();
	 if (INST_top.DEF_WILL_FIRE_RL_r_recv_gcd)
	   INST_top.RL_r_recv_gcd();
	 if (INST_top.DEF_WILL_FIRE_RL_r_recv_gcd2)
	   INST_top.RL_r_recv_gcd2();
	 if (INST_top.DEF_WILL_FIRE_RL_r_send_gcd2)
	   INST_top.RL_r_send_gcd2();
	 if (INST_top.DEF_WILL_FIRE_RL_r_send_gcd)
	   INST_top.RL_r_send_gcd();
	 if (do_reset_ticks(simHdl))
	 {
	   INST_top.INST_gcd_x.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_gcd_y.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_gcd_input_valid.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_gcd_output_valid.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_state.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_state2.rst_tick__clk__1((tUInt8)1u);
	 }
       };

/* Model creation/destruction functions */

void MODEL_mkTbGCD::create_model(tSimStateHdl simHdl, bool master)
{
  sim_hdl = simHdl;
  init_reset_request_counters(sim_hdl);
  mkTbGCD_instance = new MOD_mkTbGCD(sim_hdl, "top", NULL);
  bk_get_or_define_clock(sim_hdl, "CLK");
  if (master)
  {
    bk_alter_clock(sim_hdl, bk_get_clock_by_name(sim_hdl, "CLK"), CLK_LOW, false, 0llu, 5llu, 5llu);
    bk_use_default_reset(sim_hdl);
  }
  bk_set_clock_event_fn(sim_hdl,
			bk_get_clock_by_name(sim_hdl, "CLK"),
			schedule_posedge_CLK,
			NULL,
			(tEdgeDirection)(POSEDGE));
  (mkTbGCD_instance->set_clk_0)("CLK");
}
void MODEL_mkTbGCD::destroy_model()
{
  delete mkTbGCD_instance;
  mkTbGCD_instance = NULL;
}
void MODEL_mkTbGCD::reset_model(bool asserted)
{
  (mkTbGCD_instance->reset_RST_N)(asserted ? (tUInt8)0u : (tUInt8)1u);
}
void * MODEL_mkTbGCD::get_instance()
{
  return mkTbGCD_instance;
}

/* Fill in version numbers */
void MODEL_mkTbGCD::get_version(unsigned int *year,
				unsigned int *month,
				char const **annotation,
				char const **build)
{
  *year = 2016u;
  *month = 7u;
  *annotation = "beta1";
  *build = "34806";
}

/* Get the model creation time */
time_t MODEL_mkTbGCD::get_creation_time()
{
  
  /* Sat Mar 10 19:16:13 UTC 2018 */
  return 1520709373llu;
}

/* Control run-time licensing */
tUInt64 MODEL_mkTbGCD::skip_license_check()
{
  return 0llu;
}

/* State dumping function */
void MODEL_mkTbGCD::dump_state()
{
  (mkTbGCD_instance->dump_state)(0u);
}

/* VCD dumping functions */
MOD_mkTbGCD & mkTbGCD_backing(tSimStateHdl simHdl)
{
  static MOD_mkTbGCD *instance = NULL;
  if (instance == NULL)
  {
    vcd_set_backing_instance(simHdl, true);
    instance = new MOD_mkTbGCD(simHdl, "top", NULL);
    vcd_set_backing_instance(simHdl, false);
  }
  return *instance;
}
void MODEL_mkTbGCD::dump_VCD_defs()
{
  (mkTbGCD_instance->dump_VCD_defs)(vcd_depth(sim_hdl));
}
void MODEL_mkTbGCD::dump_VCD(tVCDDumpType dt)
{
  (mkTbGCD_instance->dump_VCD)(dt, vcd_depth(sim_hdl), mkTbGCD_backing(sim_hdl));
}