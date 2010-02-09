#ifndef PW92_H
#define PW92_H

namespace pw92_internal
{

  const char *pw92_reference = 
    "Electron-gas correlation energy\n"
    "J.P.Perdew,Y. Wang; Phys. Rew. B; 40, 13244, (1992)\n";

  template<class num>
  static num e(const num &r, const double t[7])
  {
    return -2*t[0]*(1+t[1]*r)*
      log(1+0.5/(t[0]*(t[2]*sqrt(r)+t[3]*r+t[4]*
		       pow(r,3.0/2)+t[5]*pow(r,t[6]+1))));
  }

  template<class num>
  static num omega(const num &z)
  {
    return (pow(1+z,4.0/3)+pow(1-z,4.0/3)-2)/(2*pow(2,1.0/3)-2);
  }

  template<class num>
  static num pw92_eps(const num &R, const num &zeta)
  {
    // The T..P parameters, but transposed for easier use with the e function
    const double TUVWXYP[3][7] = 
      {{0.031091, 0.21370, 7.5957 , 3.5876, 1.6382 ,0.49294,1},
       {0.01554 , 0.20548, 14.1189, 6.1977, 3.3662 ,0.62517,1},
       {0.016887, 0.11125, 10.357 , 3.6231, 0.88026,0.49671,1}};
    const double c = 1.709921;
    num rval = 0.25*pow(3,1.0/3)*pow(4,2.0/3)*pow(1/(M_PI*R),1.0/3);
    num zeta4 = pow(zeta,4);
    num omegaval = omega(zeta);
    return e(rval,TUVWXYP[0])
      -  e(rval,TUVWXYP[2])*omegaval*(1-zeta4)/c 
      + (e(rval,TUVWXYP[1]) - e(rval,TUVWXYP[0]))*omegaval*zeta4;
  }
  // This is with the Daresbury parameters for PBEc, not exactly
  // the same as for Daresbury pw92. 
  template<class num>
  static num pw92_eps_pbe(const num &R, const num &zeta)
  {
    // The T..P parameters, but transposed for easier use with the e function
    const double TUVWXYP[3][7] = 
      {{0.0310907, 0.21370, 7.5957 , 3.5876, 1.6382 ,0.49294,1},
       {0.01554535 , 0.20548, 14.1189, 6.1977, 3.3662 ,0.62517,1},
       {0.0168869, 0.11125, 10.357 , 3.6231, 0.88026,0.49671,1}};
    //    const double c = 1.709921;
    const double c = 8.0/(9.0*(2*pow(2,1.0/3.0)-2));
    num rval = 0.25*pow(3,1.0/3)*pow(4,2.0/3)*pow(M_PI*R,-1.0/3);
    num zeta4 = pow(zeta,4);
    num omegaval = omega(zeta);
    return e(rval,TUVWXYP[0])
      -  e(rval,TUVWXYP[2])*omegaval*(1-zeta4)/c 
      + (e(rval,TUVWXYP[1]) - e(rval,TUVWXYP[0]))*omegaval*zeta4;
  }
}


template<class num>
static num pw92_correlation(const num &R, const num &zeta)
{
  return R*pw92_eps(R,zeta);
}

using pw92_internal::pw92_eps;
using pw92_internal::pw92_eps_pbe;

#endif