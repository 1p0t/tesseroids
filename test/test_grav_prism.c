/* 
Unit tests for grav_prism.c functions.
*/

#include <stdio.h>
#include <math.h>
#include "../src/lib/grav_sphere.h"
#include "../src/lib/grav_prism.h"
#include "../src/lib/geometry.h"
#include "../src/lib/constants.h"


char msg[1000];

static char * test_prism2sphere_pot()
{
    SPHERE sphere;
    PRISM prism = {3000,-5000,5000,-5000,5000,-5000,5000};
    double dist, resprism, ressphere;

    /* Make a sphere with the same mass as the prism and put it at the origin */
    prism2sphere(prism, 0, 0, 0, &sphere);

    for(dist=50000; dist <= 500000; dist += 500)
    {
        resprism = prism_pot(prism,0,0,-dist);
        ressphere = sphere_pot(sphere,0,90,dist);

        sprintf(msg, "(distance %g m) prism = %.5f  sphere = %.5f", dist,
                resprism, ressphere);
        mu_assert_almost_equals(resprism, ressphere, 0.001, msg);
    }

    return 0;
}

static char * test_prism2sphere_gx()
{
    SPHERE sphere;
    PRISM prism = {3000,-5000,5000,-5000,5000,-5000,5000};
    double dist, resprism, ressphere;
    
    /* Make a sphere with the same mass as the prism and put it at the origin */
    prism2sphere(prism, 0, 0, 0, &sphere);

    for(dist=10000; dist <= 500000; dist += 500)
    {
        resprism = prism_gx(prism,0,0,-dist);
        ressphere = sphere_gx(sphere,0,90,dist);

        sprintf(msg, "(distance %g m) prism = %.5f  sphere = %.5f", dist,
                resprism, ressphere);
        mu_assert_almost_equals(resprism, ressphere, 0.00000001, msg);
    }
    
    return 0;
}


static char * test_prism2sphere_gy()
{
    SPHERE sphere;
    PRISM prism = {3000,-5000,5000,-5000,5000,-5000,5000};
    double dist, resprism, ressphere;

    /* Make a sphere with the same mass as the prism and put it at the origin */
    prism2sphere(prism, 0, 0, 0, &sphere);

    for(dist=10000; dist <= 500000; dist += 500)
    {
        resprism = prism_gy(prism,0,0,-dist);
        ressphere = sphere_gy(sphere,0,90,dist);

        sprintf(msg, "(distance %g m) prism = %.5f  sphere = %.5f", dist,
                resprism, ressphere);
        mu_assert_almost_equals(resprism, ressphere, 0.00000001, msg);
    }

    return 0;
}


static char * test_prism2sphere_gz()
{
    SPHERE sphere;
    PRISM prism = {3000,-5000,5000,-5000,5000,-5000,5000};
    double dist, resprism, ressphere;

    /* Make a sphere with the same mass as the prism and put it at the origin */
    prism2sphere(prism, 0, 0, 0, &sphere);

    for(dist=50000; dist <= 500000; dist += 500)
    {
        resprism = prism_gz(prism,0,0,-dist);
        ressphere = sphere_gz(sphere,0,90,dist);

        sprintf(msg, "(distance %g m) prism = %.5f  sphere = %.5f", dist,
                resprism, ressphere);
        mu_assert_almost_equals(resprism, -1*ressphere, 0.01, msg);
    }

    return 0;
}


static char * test_prism2sphere_gxx()
{
    SPHERE sphere;
    PRISM prism = {3000,-5000,5000,-5000,5000,-5000,5000};
    double dist, resprism, ressphere;

    /* Make a sphere with the same mass as the prism and put it at the origin */
    prism2sphere(prism, 0, 0, 0, &sphere);

    for(dist=50000; dist <= 500000; dist += 500)
    {
        resprism = prism_gxx(prism,0,0,-dist);
        ressphere = sphere_gxx(sphere,0,90,dist);

        sprintf(msg, "(distance %g m) prism = %.5f  sphere = %.5f", dist,
                resprism, ressphere);
        mu_assert_almost_equals(resprism, ressphere, 0.001, msg);
    }

    return 0;
}


static char * test_prism2sphere_gxy()
{
    SPHERE sphere;
    PRISM prism = {3000,-5000,5000,-5000,5000,-5000,5000};
    double dist, resprism, ressphere;

    /* Make a sphere with the same mass as the prism and put it at the origin */
    prism2sphere(prism, 0, 0, 0, &sphere);

    for(dist=50000; dist <= 500000; dist += 500)
    {
        resprism = prism_gxy(prism,0,0,-dist);
        ressphere = sphere_gxy(sphere,0,90,dist);

        sprintf(msg, "(distance %g m) prism = %.5f  sphere = %.5f", dist,
                resprism, ressphere);
        mu_assert_almost_equals(resprism, ressphere, 0.001, msg);
    }

    return 0;
}


static char * test_prism2sphere_gxz()
{
    SPHERE sphere;
    PRISM prism = {3000,-5000,5000,-5000,5000,-5000,5000};
    double dist, resprism, ressphere;

    /* Make a sphere with the same mass as the prism and put it at the origin */
    prism2sphere(prism, 0, 0, 0, &sphere);

    for(dist=50000; dist <= 500000; dist += 500)
    {
        resprism = prism_gxz(prism,0,0,-dist);
        ressphere = sphere_gxz(sphere,0,90,dist);

        sprintf(msg, "(distance %g m) prism = %.5f  sphere = %.5f", dist,
                resprism, ressphere);
        mu_assert_almost_equals(resprism, -1*ressphere, 0.001, msg);
    }

    return 0;
}


static char * test_prism2sphere_gyy()
{
    SPHERE sphere;
    PRISM prism = {3000,-5000,5000,-5000,5000,-5000,5000};
    double dist, resprism, ressphere;

    /* Make a sphere with the same mass as the prism and put it at the origin */
    prism2sphere(prism, 0, 0, 0, &sphere);

    for(dist=50000; dist <= 500000; dist += 500)
    {
        resprism = prism_gyy(prism,0,0,-dist);
        ressphere = sphere_gyy(sphere,0,90,dist);

        sprintf(msg, "(distance %g m) prism = %.5f  sphere = %.5f", dist,
                resprism, ressphere);
        mu_assert_almost_equals(resprism, ressphere, 0.001, msg);
    }

    return 0;
}


static char * test_prism2sphere_gyz()
{
    SPHERE sphere;
    PRISM prism = {3000,-5000,5000,-5000,5000,-5000,5000};
    double dist, resprism, ressphere;

    /* Make a sphere with the same mass as the prism and put it at the origin */
    prism2sphere(prism, 0, 0, 0, &sphere);

    for(dist=50000; dist <= 500000; dist += 500)
    {
        resprism = prism_gyz(prism,0,0,-dist);
        ressphere = sphere_gyz(sphere,0,90,dist);

        sprintf(msg, "(distance %g m) prism = %.5f  sphere = %.5f", dist,
                resprism, ressphere);
        mu_assert_almost_equals(resprism, -1*ressphere, 0.001, msg);
    }

    return 0;
}


static char * test_prism2sphere_gzz()
{
    SPHERE sphere;
    PRISM prism = {3000,-5000,5000,-5000,5000,-5000,5000};
    double dist, resprism, ressphere;

    /* Make a sphere with the same mass as the prism and put it at the origin */
    prism2sphere(prism, 0, 0, 0, &sphere);

    for(dist=60000; dist <= 500000; dist += 500)
    {
        resprism = prism_gzz(prism,0,0,-dist);
        ressphere = sphere_gzz(sphere,0,90,dist);

        sprintf(msg, "(distance %g m) prism = %.5f  sphere = %.5f", dist,
                resprism, ressphere);
        mu_assert_almost_equals(resprism, ressphere, 0.001, msg);
    }

    return 0;
}


void grav_prism_run_all()
{
    mu_run_test(test_prism2sphere_pot,
                "prism_pot results equal to sphere of same mass at distance");
    mu_run_test(test_prism2sphere_gx,
                "prism_gx results equal to sphere of same mass at distance");
    mu_run_test(test_prism2sphere_gy,
                "prism_gy results equal to sphere of same mass at distance");
    mu_run_test(test_prism2sphere_gz,
                "prism_gz results equal to sphere of same mass at distance");
    mu_run_test(test_prism2sphere_gxx,
                "prism_gxx results equal to sphere of same mass at distance");
    mu_run_test(test_prism2sphere_gxy,
                "prism_gxy results equal to sphere of same mass at distance");
    mu_run_test(test_prism2sphere_gxz,
                "prism_gxz results equal to sphere of same mass at distance");
    mu_run_test(test_prism2sphere_gyy,
                "prism_gyy results equal to sphere of same mass at distance");
    mu_run_test(test_prism2sphere_gyz,
                "prism_gyz results equal to sphere of same mass at distance");
    mu_run_test(test_prism2sphere_gzz,
                "prism_gzz results equal to sphere of same mass at distance");
}
