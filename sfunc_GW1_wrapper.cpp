
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <string>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 64

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
extern uint8_t* custom_stringToInt8(const std::string& str);
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void sfunc_GW1_Outputs_wrapper(const boolean_T *gw_input_mid,
			uint8_T *gw_output)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
//Request certificate from GSE if Transmission is started
    std::string cmd_gw_to_gse = "requestValidCertificate";
    if (*gw_input_mid == true){
        //Convert string to uint8 Array
        std::copy(cmd_gw_to_gse.begin(), cmd_gw_to_gse.end(), gw_output);
    } else gw_output = nullptr;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


