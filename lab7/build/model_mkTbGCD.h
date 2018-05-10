/*
 * Generated by Bluespec Compiler, version 2016.07.beta1 (build 34806, 2016-07-05)
 * 
 * On Sat Mar 10 11:16:13 PST 2018
 * 
 */

/* Generation options: keep-fires */
#ifndef __model_mkTbGCD_h__
#define __model_mkTbGCD_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"

#include "bs_model.h"
#include "mkTbGCD.h"

/* Class declaration for a model of mkTbGCD */
class MODEL_mkTbGCD : public Model {
 
 /* Top-level module instance */
 private:
  MOD_mkTbGCD *mkTbGCD_instance;
 
 /* Handle to the simulation kernel */
 private:
  tSimStateHdl sim_hdl;
 
 /* Constructor */
 public:
  MODEL_mkTbGCD();
 
 /* Functions required by the kernel */
 public:
  void create_model(tSimStateHdl simHdl, bool master);
  void destroy_model();
  void reset_model(bool asserted);
  void get_version(unsigned int *year,
		   unsigned int *month,
		   char const **annotation,
		   char const **build);
  time_t get_creation_time();
  void * get_instance();
  void dump_state();
  void dump_VCD_defs();
  void dump_VCD(tVCDDumpType dt);
  tUInt64 skip_license_check();
};

/* Function for creating a new model */
extern "C" {
  void * new_MODEL_mkTbGCD();
}

#endif /* ifndef __model_mkTbGCD_h__ */
