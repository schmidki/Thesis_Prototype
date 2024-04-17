
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
#include <custom_keysave.h>
#include <osrng.h>
#include <rsa.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 4096

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void sfunc_GSE2_Outputs_wrapper(const uint8_T *gse_input,
			uint8_T *gse_output_plain,
			uint8_T *gse_output_cipher)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
using namespace CryptoPP;
    AutoSeededRandomPool rng;
    RSA::PrivateKey privateKey;
    std::string output_str_plain, output_str_cipher;
    
    //Load Key
    LoadPrivateKey("rsa-private.key", privateKey);
    
    //Convert from uint8 Array to string
    //output_str_cipher = (char *) gse_input;
    output_str_cipher = std::string(reinterpret_cast<const char*>(gse_input), 88);
    
    // Decryption
    RSAES_OAEP_SHA_Decryptor d(privateKey);

    StringSource ss2(output_str_cipher, true,
        new PK_DecryptorFilter(rng, d,
            new StringSink(output_str_plain)
            ) // PK_DecryptorFilter
    ); // StringSource
    
    //Convert strings to uint8 Arrays
    std::copy(output_str_plain.begin(), output_str_plain.end(), gse_output_plain);
    std::copy(output_str_cipher.begin(), output_str_cipher.end(), gse_output_cipher);
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


