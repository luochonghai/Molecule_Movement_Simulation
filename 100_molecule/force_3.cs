using System.Collections;
using System.Collections.Generic;
using System;
using UnityEngine;

public class force_3 : MonoBehaviour
{
    public GameObject player;
    public Rigidbody rb1;public Rigidbody rb2;public Rigidbody rb3;public Rigidbody rb4;
    public Rigidbody rb5; public Rigidbody rb6; public Rigidbody rb7; public Rigidbody rb8;
    public Rigidbody rb9; public Rigidbody rb10; public Rigidbody rb11; public Rigidbody rb12;
    public Rigidbody rb13; public Rigidbody rb14; public Rigidbody rb15; public Rigidbody rb16;
    public Rigidbody rb17; public Rigidbody rb18; public Rigidbody rb19; public Rigidbody rb20;
    public Rigidbody rb21; public Rigidbody rb22; public Rigidbody rb23; public Rigidbody rb24;
    public Rigidbody rb25; public Rigidbody rb26; public Rigidbody rb27; public Rigidbody rb28;
    public Rigidbody rb29; public Rigidbody rb30; public Rigidbody rb31; public Rigidbody rb32;
    public Rigidbody rb33; public Rigidbody rb34; public Rigidbody rb35; public Rigidbody rb36;
    public Rigidbody rb37; public Rigidbody rb38; public Rigidbody rb39; public Rigidbody rb40;
    public Rigidbody rb41; public Rigidbody rb42; public Rigidbody rb43; public Rigidbody rb44;
    public Rigidbody rb45; public Rigidbody rb46; public Rigidbody rb47; public Rigidbody rb48;
    public Rigidbody rb49; public Rigidbody rb50; public Rigidbody rb51; public Rigidbody rb52;
    public Rigidbody rb53; public Rigidbody rb54; public Rigidbody rb55; public Rigidbody rb56;
    public Rigidbody rb57; public Rigidbody rb58; public Rigidbody rb59; public Rigidbody rb60;
    public Rigidbody rb61; public Rigidbody rb62; public Rigidbody rb63; public Rigidbody rb64;
    public Rigidbody rb65; public Rigidbody rb66; public Rigidbody rb67; public Rigidbody rb68;
    public Rigidbody rb69; public Rigidbody rb70; public Rigidbody rb71; public Rigidbody rb72;
    public Rigidbody rb73; public Rigidbody rb74; public Rigidbody rb75; public Rigidbody rb76;
    public Rigidbody rb77; public Rigidbody rb78; public Rigidbody rb79; public Rigidbody rb80;
    public Rigidbody rb81; public Rigidbody rb82; public Rigidbody rb83; public Rigidbody rb84;
    public Rigidbody rb85; public Rigidbody rb86; public Rigidbody rb87; public Rigidbody rb88;
    public Rigidbody rb89; public Rigidbody rb90; public Rigidbody rb91; public Rigidbody rb92;
    public Rigidbody rb93; public Rigidbody rb94; public Rigidbody rb95; public Rigidbody rb96;
    public Rigidbody rb97; public Rigidbody rb98; public Rigidbody rb99; 
    public GameObject sphere1; public GameObject sphere2; public GameObject sphere3;
    public GameObject sphere4; public GameObject sphere5; public GameObject sphere6;
    public GameObject sphere7; public GameObject sphere8; public GameObject sphere9;
    public GameObject sphere10;public GameObject sphere11; public GameObject sphere12;
    public GameObject sphere13; public GameObject sphere14; public GameObject sphere15;
    public GameObject sphere16; public GameObject sphere17; public GameObject sphere18;
    public GameObject sphere19; public GameObject sphere20; public GameObject sphere21;
    public GameObject sphere22; public GameObject sphere23; public GameObject sphere24;
    public GameObject sphere25; public GameObject sphere26; public GameObject sphere27;
    public GameObject sphere28; public GameObject sphere29; public GameObject sphere30;
    public GameObject sphere31; public GameObject sphere32; public GameObject sphere33;
    public GameObject sphere34; public GameObject sphere35; public GameObject sphere36;
    public GameObject sphere37; public GameObject sphere38; public GameObject sphere39;
    public GameObject sphere40; public GameObject sphere41; public GameObject sphere42;
    public GameObject sphere43; public GameObject sphere44; public GameObject sphere45;
    public GameObject sphere46; public GameObject sphere47; public GameObject sphere48;
    public GameObject sphere49; public GameObject sphere50; public GameObject sphere51;
    public GameObject sphere52; public GameObject sphere53; public GameObject sphere54;
    public GameObject sphere55; public GameObject sphere56; public GameObject sphere57;
    public GameObject sphere58; public GameObject sphere59; public GameObject sphere60;
    public GameObject sphere61; public GameObject sphere62; public GameObject sphere63;
    public GameObject sphere64; public GameObject sphere65; public GameObject sphere66;
    public GameObject sphere67; public GameObject sphere68; public GameObject sphere69;
    public GameObject sphere70; public GameObject sphere71; public GameObject sphere72;
    public GameObject sphere73; public GameObject sphere74; public GameObject sphere75;
    public GameObject sphere76; public GameObject sphere77; public GameObject sphere78;
    public GameObject sphere79; public GameObject sphere80; public GameObject sphere81;
    public GameObject sphere82; public GameObject sphere83; public GameObject sphere84;
    public GameObject sphere85; public GameObject sphere86; public GameObject sphere87;
    public GameObject sphere88; public GameObject sphere89; public GameObject sphere90;
    public GameObject sphere91; public GameObject sphere92; public GameObject sphere93;
    public GameObject sphere94; public GameObject sphere95; public GameObject sphere96;
    public GameObject sphere97; public GameObject sphere98; public GameObject sphere99;
    public float delta_x;
    public float delta_y;
    public float delta_z;

    void Start()
    {
        rb1 = GetComponent<Rigidbody>(); rb2 = GetComponent<Rigidbody>();rb3 = GetComponent<Rigidbody>();rb4 = GetComponent<Rigidbody>();
        rb5 = GetComponent<Rigidbody>(); rb6 = GetComponent<Rigidbody>(); rb7 = GetComponent<Rigidbody>(); rb8 = GetComponent<Rigidbody>();
        rb9 = GetComponent<Rigidbody>(); rb10 = GetComponent<Rigidbody>(); rb11 = GetComponent<Rigidbody>(); rb12 = GetComponent<Rigidbody>();
        rb13 = GetComponent<Rigidbody>(); rb14 = GetComponent<Rigidbody>(); rb15 = GetComponent<Rigidbody>(); rb16 = GetComponent<Rigidbody>();
        rb17 = GetComponent<Rigidbody>(); rb18 = GetComponent<Rigidbody>(); rb19 = GetComponent<Rigidbody>(); rb20 = GetComponent<Rigidbody>();
        rb21 = GetComponent<Rigidbody>(); rb22 = GetComponent<Rigidbody>(); rb23 = GetComponent<Rigidbody>(); rb24 = GetComponent<Rigidbody>();
        rb25 = GetComponent<Rigidbody>(); rb26 = GetComponent<Rigidbody>(); rb27 = GetComponent<Rigidbody>(); rb28 = GetComponent<Rigidbody>();
        rb29 = GetComponent<Rigidbody>(); rb30 = GetComponent<Rigidbody>(); rb31 = GetComponent<Rigidbody>(); rb32 = GetComponent<Rigidbody>();
        rb33 = GetComponent<Rigidbody>(); rb34 = GetComponent<Rigidbody>(); rb35 = GetComponent<Rigidbody>(); rb36 = GetComponent<Rigidbody>();
        rb37 = GetComponent<Rigidbody>(); rb38 = GetComponent<Rigidbody>(); rb39 = GetComponent<Rigidbody>(); rb40 = GetComponent<Rigidbody>();
        rb41 = GetComponent<Rigidbody>(); rb42 = GetComponent<Rigidbody>(); rb43 = GetComponent<Rigidbody>(); rb44 = GetComponent<Rigidbody>();
        rb45 = GetComponent<Rigidbody>(); rb46 = GetComponent<Rigidbody>(); rb47 = GetComponent<Rigidbody>(); rb48 = GetComponent<Rigidbody>();
        rb49 = GetComponent<Rigidbody>(); rb50 = GetComponent<Rigidbody>(); rb51 = GetComponent<Rigidbody>(); rb52 = GetComponent<Rigidbody>();
        rb53 = GetComponent<Rigidbody>(); rb54 = GetComponent<Rigidbody>(); rb55 = GetComponent<Rigidbody>(); rb56 = GetComponent<Rigidbody>();
        rb57 = GetComponent<Rigidbody>(); rb58 = GetComponent<Rigidbody>(); rb59 = GetComponent<Rigidbody>(); rb60 = GetComponent<Rigidbody>();
        rb61 = GetComponent<Rigidbody>(); rb62 = GetComponent<Rigidbody>(); rb63 = GetComponent<Rigidbody>(); rb64 = GetComponent<Rigidbody>();
        rb65 = GetComponent<Rigidbody>(); rb66 = GetComponent<Rigidbody>(); rb67 = GetComponent<Rigidbody>(); rb68 = GetComponent<Rigidbody>();
        rb69 = GetComponent<Rigidbody>(); rb70 = GetComponent<Rigidbody>(); rb71 = GetComponent<Rigidbody>(); rb72 = GetComponent<Rigidbody>();
        rb73 = GetComponent<Rigidbody>(); rb74 = GetComponent<Rigidbody>(); rb75 = GetComponent<Rigidbody>(); rb76 = GetComponent<Rigidbody>();
        rb77 = GetComponent<Rigidbody>(); rb78 = GetComponent<Rigidbody>(); rb79 = GetComponent<Rigidbody>(); rb80 = GetComponent<Rigidbody>();
        rb81 = GetComponent<Rigidbody>(); rb82 = GetComponent<Rigidbody>(); rb83 = GetComponent<Rigidbody>(); rb84 = GetComponent<Rigidbody>();
        rb85 = GetComponent<Rigidbody>(); rb86 = GetComponent<Rigidbody>(); rb87 = GetComponent<Rigidbody>(); rb88 = GetComponent<Rigidbody>();
        rb89 = GetComponent<Rigidbody>(); rb90 = GetComponent<Rigidbody>(); rb91 = GetComponent<Rigidbody>(); rb92 = GetComponent<Rigidbody>();
        rb93 = GetComponent<Rigidbody>(); rb94 = GetComponent<Rigidbody>(); rb95 = GetComponent<Rigidbody>(); rb96 = GetComponent<Rigidbody>();
        rb97 = GetComponent<Rigidbody>(); rb98 = GetComponent<Rigidbody>(); rb99 = GetComponent<Rigidbody>();
    }

    float[] Force_cal(Vector3 player_position,Vector3 sphere1_position)
    {
        float delta_x = player_position.x - sphere1_position.x;
        float delta_y = player_position.y - sphere1_position.y;
        float delta_z = player_position.z - sphere1_position.z;
        double dist = delta_x * delta_x + delta_y * delta_y + delta_z * delta_z;
        float distance = float.Parse((Math.Sqrt(dist)).ToString());
        float mul_k = 3;
        float force_b = 4000f;
        float Force_2 = mul_k / distance / distance / distance - 1 / distance / distance;
        Force_2 *= force_b;
        float[] res = new float[3];
        res[0] = delta_x * Force_2 / distance;
        res[1] = delta_y * Force_2 / distance;
        res[2] = delta_z * Force_2 / distance;
        return res;
    }

    void FixedUpdate()
    {
        Dictionary<string, GameObject> sphere_ori = new Dictionary<string, GameObject>();
        Vector3 player_position = player.transform.position;
        //Vector3[] sphere_position = new Vector3[99];  
        //try to use reflection!!!



        Vector3 sphere1_position = sphere1.transform.position;Vector3 sphere2_position = sphere2.transform.position;Vector3 sphere3_position = sphere3.transform.position;
        Vector3 sphere4_position = sphere4.transform.position; Vector3 sphere5_position = sphere5.transform.position; Vector3 sphere6_position = sphere6.transform.position;
        Vector3 sphere7_position = sphere7.transform.position; Vector3 sphere8_position = sphere8.transform.position; Vector3 sphere9_position = sphere9.transform.position;
        Vector3 sphere10_position = sphere10.transform.position; Vector3 sphere11_position = sphere11.transform.position; Vector3 sphere12_position = sphere12.transform.position;
        Vector3 sphere13_position = sphere13.transform.position; Vector3 sphere14_position = sphere14.transform.position; Vector3 sphere15_position = sphere15.transform.position;
        Vector3 sphere16_position = sphere16.transform.position; Vector3 sphere17_position = sphere17.transform.position; Vector3 sphere18_position = sphere18.transform.position;
        Vector3 sphere19_position = sphere19.transform.position; Vector3 sphere20_position = sphere20.transform.position; Vector3 sphere21_position = sphere21.transform.position;
        Vector3 sphere22_position = sphere22.transform.position; Vector3 sphere23_position = sphere23.transform.position; Vector3 sphere24_position = sphere24.transform.position;
        Vector3 sphere25_position = sphere25.transform.position; Vector3 sphere26_position = sphere26.transform.position; Vector3 sphere27_position = sphere27.transform.position;
        Vector3 sphere28_position = sphere28.transform.position; Vector3 sphere29_position = sphere29.transform.position; Vector3 sphere30_position = sphere30.transform.position;
        Vector3 sphere31_position = sphere31.transform.position; Vector3 sphere32_position = sphere32.transform.position; Vector3 sphere33_position = sphere33.transform.position;
        Vector3 sphere34_position = sphere34.transform.position; Vector3 sphere35_position = sphere35.transform.position; Vector3 sphere36_position = sphere36.transform.position;
        Vector3 sphere37_position = sphere37.transform.position; Vector3 sphere38_position = sphere38.transform.position; Vector3 sphere39_position = sphere39.transform.position;
        Vector3 sphere40_position = sphere40.transform.position; Vector3 sphere41_position = sphere41.transform.position; Vector3 sphere42_position = sphere42.transform.position;
        Vector3 sphere43_position = sphere43.transform.position; Vector3 sphere44_position = sphere44.transform.position; Vector3 sphere45_position = sphere45.transform.position;
        Vector3 sphere46_position = sphere46.transform.position; Vector3 sphere47_position = sphere47.transform.position; Vector3 sphere48_position = sphere48.transform.position;
        Vector3 sphere49_position = sphere49.transform.position; Vector3 sphere50_position = sphere50.transform.position; Vector3 sphere51_position = sphere51.transform.position;
        Vector3 sphere52_position = sphere52.transform.position; Vector3 sphere53_position = sphere53.transform.position; Vector3 sphere54_position = sphere54.transform.position;
        Vector3 sphere55_position = sphere55.transform.position; Vector3 sphere56_position = sphere56.transform.position; Vector3 sphere57_position = sphere57.transform.position;
        Vector3 sphere58_position = sphere58.transform.position; Vector3 sphere59_position = sphere59.transform.position; Vector3 sphere60_position = sphere60.transform.position;
        Vector3 sphere61_position = sphere61.transform.position; Vector3 sphere62_position = sphere62.transform.position; Vector3 sphere63_position = sphere63.transform.position;
        Vector3 sphere64_position = sphere64.transform.position; Vector3 sphere65_position = sphere65.transform.position; Vector3 sphere66_position = sphere66.transform.position;
        Vector3 sphere67_position = sphere67.transform.position; Vector3 sphere68_position = sphere68.transform.position; Vector3 sphere69_position = sphere69.transform.position;
        Vector3 sphere70_position = sphere70.transform.position; Vector3 sphere71_position = sphere71.transform.position; Vector3 sphere72_position = sphere72.transform.position;
        Vector3 sphere73_position = sphere73.transform.position; Vector3 sphere74_position = sphere74.transform.position; Vector3 sphere75_position = sphere75.transform.position;
        Vector3 sphere76_position = sphere76.transform.position; Vector3 sphere77_position = sphere77.transform.position; Vector3 sphere78_position = sphere78.transform.position;
        Vector3 sphere79_position = sphere79.transform.position; Vector3 sphere80_position = sphere80.transform.position; Vector3 sphere81_position = sphere81.transform.position;
        Vector3 sphere82_position = sphere82.transform.position; Vector3 sphere83_position = sphere83.transform.position; Vector3 sphere84_position = sphere84.transform.position;
        Vector3 sphere85_position = sphere85.transform.position; Vector3 sphere86_position = sphere86.transform.position; Vector3 sphere87_position = sphere87.transform.position;
        Vector3 sphere88_position = sphere88.transform.position; Vector3 sphere89_position = sphere89.transform.position; Vector3 sphere90_position = sphere90.transform.position;
        Vector3 sphere91_position = sphere91.transform.position; Vector3 sphere92_position = sphere92.transform.position; Vector3 sphere93_position = sphere93.transform.position;
        Vector3 sphere94_position = sphere94.transform.position; Vector3 sphere95_position = sphere95.transform.position; Vector3 sphere96_position = sphere96.transform.position;
        Vector3 sphere97_position = sphere97.transform.position; Vector3 sphere98_position = sphere98.transform.position; Vector3 sphere99_position = sphere99.transform.position;

        float[] res1 = Force_cal(player_position, sphere1_position);float[] res2 = Force_cal(player_position, sphere2_position);float[] res3 = Force_cal(player_position, sphere3_position);
        float[] res4 = Force_cal(player_position, sphere4_position); float[] res5 = Force_cal(player_position, sphere5_position); float[] res6 = Force_cal(player_position, sphere6_position);
        float[] res7 = Force_cal(player_position, sphere7_position); float[] res8 = Force_cal(player_position, sphere8_position); float[] res9 = Force_cal(player_position, sphere9_position);
        float[] res10 = Force_cal(player_position, sphere10_position); float[] res11 = Force_cal(player_position, sphere11_position); float[] res12 = Force_cal(player_position, sphere12_position);
        float[] res13 = Force_cal(player_position, sphere13_position); float[] res14 = Force_cal(player_position, sphere14_position); float[] res15 = Force_cal(player_position, sphere15_position);
        float[] res16 = Force_cal(player_position, sphere16_position); float[] res17 = Force_cal(player_position, sphere17_position); float[] res18 = Force_cal(player_position, sphere18_position);
        float[] res19 = Force_cal(player_position, sphere19_position); float[] res20 = Force_cal(player_position, sphere20_position); float[] res21 = Force_cal(player_position, sphere21_position);
        float[] res22 = Force_cal(player_position, sphere22_position); float[] res23 = Force_cal(player_position, sphere23_position); float[] res24 = Force_cal(player_position, sphere24_position);
        float[] res25 = Force_cal(player_position, sphere25_position); float[] res26 = Force_cal(player_position, sphere26_position); float[] res27 = Force_cal(player_position, sphere27_position);
        float[] res28 = Force_cal(player_position, sphere28_position); float[] res29 = Force_cal(player_position, sphere29_position); float[] res30 = Force_cal(player_position, sphere30_position);
        float[] res31 = Force_cal(player_position, sphere31_position); float[] res32 = Force_cal(player_position, sphere32_position); float[] res33 = Force_cal(player_position, sphere33_position);
        float[] res34 = Force_cal(player_position, sphere34_position); float[] res35 = Force_cal(player_position, sphere35_position); float[] res36 = Force_cal(player_position, sphere36_position);
        float[] res37 = Force_cal(player_position, sphere37_position); float[] res38 = Force_cal(player_position, sphere38_position); float[] res39 = Force_cal(player_position, sphere39_position);
        float[] res40 = Force_cal(player_position, sphere40_position); float[] res41 = Force_cal(player_position, sphere41_position); float[] res42 = Force_cal(player_position, sphere42_position);
        float[] res43 = Force_cal(player_position, sphere43_position); float[] res44 = Force_cal(player_position, sphere44_position); float[] res45 = Force_cal(player_position, sphere45_position);
        float[] res46 = Force_cal(player_position, sphere46_position); float[] res47 = Force_cal(player_position, sphere47_position); float[] res48 = Force_cal(player_position, sphere48_position);
        float[] res49 = Force_cal(player_position, sphere49_position); float[] res50 = Force_cal(player_position, sphere50_position); float[] res51 = Force_cal(player_position, sphere51_position);
        float[] res52 = Force_cal(player_position, sphere52_position); float[] res53 = Force_cal(player_position, sphere53_position); float[] res54 = Force_cal(player_position, sphere54_position);
        float[] res55 = Force_cal(player_position, sphere55_position); float[] res56 = Force_cal(player_position, sphere56_position); float[] res57 = Force_cal(player_position, sphere57_position);
        float[] res58 = Force_cal(player_position, sphere58_position); float[] res59 = Force_cal(player_position, sphere59_position); float[] res60 = Force_cal(player_position, sphere60_position);
        float[] res61 = Force_cal(player_position, sphere61_position); float[] res62 = Force_cal(player_position, sphere62_position); float[] res63 = Force_cal(player_position, sphere63_position);
        float[] res64 = Force_cal(player_position, sphere64_position); float[] res65 = Force_cal(player_position, sphere65_position); float[] res66 = Force_cal(player_position, sphere66_position);
        float[] res67 = Force_cal(player_position, sphere67_position); float[] res68 = Force_cal(player_position, sphere68_position); float[] res69 = Force_cal(player_position, sphere69_position);
        float[] res70 = Force_cal(player_position, sphere70_position); float[] res71 = Force_cal(player_position, sphere71_position); float[] res72 = Force_cal(player_position, sphere72_position);
        float[] res73 = Force_cal(player_position, sphere73_position); float[] res74 = Force_cal(player_position, sphere74_position); float[] res75 = Force_cal(player_position, sphere75_position);
        float[] res76 = Force_cal(player_position, sphere76_position); float[] res77 = Force_cal(player_position, sphere77_position); float[] res78 = Force_cal(player_position, sphere78_position);
        float[] res79 = Force_cal(player_position, sphere79_position); float[] res80 = Force_cal(player_position, sphere80_position); float[] res81 = Force_cal(player_position, sphere81_position);
        float[] res82 = Force_cal(player_position, sphere82_position); float[] res83 = Force_cal(player_position, sphere83_position); float[] res84 = Force_cal(player_position, sphere84_position);
        float[] res85 = Force_cal(player_position, sphere85_position); float[] res86 = Force_cal(player_position, sphere86_position); float[] res87 = Force_cal(player_position, sphere87_position);
        float[] res88 = Force_cal(player_position, sphere88_position); float[] res89 = Force_cal(player_position, sphere89_position); float[] res90 = Force_cal(player_position, sphere90_position);
        float[] res91 = Force_cal(player_position, sphere91_position); float[] res92 = Force_cal(player_position, sphere92_position); float[] res93 = Force_cal(player_position, sphere93_position);
        float[] res94 = Force_cal(player_position, sphere94_position); float[] res95 = Force_cal(player_position, sphere95_position); float[] res96 = Force_cal(player_position, sphere96_position);
        float[] res97 = Force_cal(player_position, sphere97_position); float[] res98 = Force_cal(player_position, sphere98_position); float[] res99 = Force_cal(player_position, sphere99_position);
        rb1.AddForce(res1[0], res1[1], res1[2], ForceMode.Force);rb2.AddForce(res2[0], res2[1], res2[2], ForceMode.Force);rb3.AddForce(res3[0], res3[1], res3[2], ForceMode.Force);
        rb4.AddForce(res4[0], res4[1], res4[2], ForceMode.Force); rb5.AddForce(res5[0], res5[1], res5[2], ForceMode.Force); rb6.AddForce(res6[0], res6[1], res6[2], ForceMode.Force);
        rb7.AddForce(res7[0], res7[1], res7[2], ForceMode.Force); rb8.AddForce(res8[0], res8[1], res8[2], ForceMode.Force); rb9.AddForce(res9[0], res9[1], res9[2], ForceMode.Force);
        rb10.AddForce(res10[0], res10[1], res10[2], ForceMode.Force); rb11.AddForce(res11[0], res11[1], res11[2], ForceMode.Force); rb12.AddForce(res12[0], res12[1], res12[2], ForceMode.Force);
        rb13.AddForce(res13[0], res13[1], res13[2], ForceMode.Force); rb14.AddForce(res14[0], res14[1], res14[2], ForceMode.Force); rb15.AddForce(res15[0], res15[1], res15[2], ForceMode.Force);
        rb16.AddForce(res16[0], res16[1], res16[2], ForceMode.Force); rb17.AddForce(res17[0], res17[1], res17[2], ForceMode.Force); rb18.AddForce(res18[0], res18[1], res18[2], ForceMode.Force);
        rb19.AddForce(res19[0], res19[1], res19[2], ForceMode.Force); rb20.AddForce(res20[0], res20[1], res20[2], ForceMode.Force); rb21.AddForce(res21[0], res21[1], res21[2], ForceMode.Force);
        rb22.AddForce(res22[0], res22[1], res22[2], ForceMode.Force); rb23.AddForce(res23[0], res23[1], res23[2], ForceMode.Force); rb24.AddForce(res24[0], res24[1], res24[2], ForceMode.Force);
        rb25.AddForce(res25[0], res25[1], res25[2], ForceMode.Force); rb26.AddForce(res26[0], res26[1], res26[2], ForceMode.Force); rb27.AddForce(res27[0], res27[1], res27[2], ForceMode.Force);
        rb28.AddForce(res28[0], res28[1], res28[2], ForceMode.Force); rb29.AddForce(res29[0], res29[1], res29[2], ForceMode.Force); rb30.AddForce(res30[0], res30[1], res30[2], ForceMode.Force);
        rb31.AddForce(res31[0], res31[1], res31[2], ForceMode.Force); rb32.AddForce(res32[0], res32[1], res32[2], ForceMode.Force); rb33.AddForce(res33[0], res33[1], res33[2], ForceMode.Force);
        rb34.AddForce(res34[0], res34[1], res34[2], ForceMode.Force); rb35.AddForce(res35[0], res35[1], res35[2], ForceMode.Force); rb36.AddForce(res36[0], res36[1], res36[2], ForceMode.Force);
        rb37.AddForce(res37[0], res37[1], res37[2], ForceMode.Force); rb38.AddForce(res38[0], res38[1], res38[2], ForceMode.Force); rb39.AddForce(res39[0], res39[1], res39[2], ForceMode.Force);
        rb40.AddForce(res40[0], res40[1], res40[2], ForceMode.Force); rb41.AddForce(res41[0], res41[1], res41[2], ForceMode.Force); rb42.AddForce(res42[0], res42[1], res42[2], ForceMode.Force);
        rb43.AddForce(res43[0], res43[1], res43[2], ForceMode.Force); rb44.AddForce(res44[0], res44[1], res44[2], ForceMode.Force); rb45.AddForce(res45[0], res45[1], res45[2], ForceMode.Force);
        rb46.AddForce(res46[0], res46[1], res46[2], ForceMode.Force); rb47.AddForce(res47[0], res47[1], res47[2], ForceMode.Force); rb48.AddForce(res48[0], res48[1], res48[2], ForceMode.Force);
        rb49.AddForce(res49[0], res49[1], res49[2], ForceMode.Force); rb50.AddForce(res50[0], res50[1], res50[2], ForceMode.Force); rb51.AddForce(res51[0], res51[1], res51[2], ForceMode.Force);
        rb52.AddForce(res52[0], res52[1], res52[2], ForceMode.Force); rb53.AddForce(res53[0], res53[1], res53[2], ForceMode.Force); rb54.AddForce(res54[0], res54[1], res54[2], ForceMode.Force);
        rb55.AddForce(res55[0], res55[1], res55[2], ForceMode.Force); rb56.AddForce(res56[0], res56[1], res56[2], ForceMode.Force); rb57.AddForce(res57[0], res57[1], res57[2], ForceMode.Force);
        rb58.AddForce(res58[0], res58[1], res58[2], ForceMode.Force); rb59.AddForce(res59[0], res59[1], res59[2], ForceMode.Force); rb60.AddForce(res60[0], res60[1], res60[2], ForceMode.Force);
        rb61.AddForce(res61[0], res61[1], res61[2], ForceMode.Force); rb62.AddForce(res62[0], res62[1], res62[2], ForceMode.Force); rb63.AddForce(res63[0], res63[1], res63[2], ForceMode.Force);
        rb64.AddForce(res64[0], res64[1], res64[2], ForceMode.Force); rb65.AddForce(res65[0], res65[1], res65[2], ForceMode.Force); rb66.AddForce(res66[0], res66[1], res66[2], ForceMode.Force);
        rb67.AddForce(res67[0], res67[1], res67[2], ForceMode.Force); rb68.AddForce(res68[0], res68[1], res68[2], ForceMode.Force); rb69.AddForce(res69[0], res69[1], res69[2], ForceMode.Force);
        rb70.AddForce(res70[0], res70[1], res70[2], ForceMode.Force); rb71.AddForce(res71[0], res71[1], res71[2], ForceMode.Force); rb72.AddForce(res72[0], res72[1], res72[2], ForceMode.Force);
        rb73.AddForce(res73[0], res73[1], res73[2], ForceMode.Force); rb74.AddForce(res74[0], res74[1], res74[2], ForceMode.Force); rb75.AddForce(res75[0], res75[1], res75[2], ForceMode.Force);
        rb76.AddForce(res76[0], res76[1], res76[2], ForceMode.Force); rb77.AddForce(res77[0], res77[1], res77[2], ForceMode.Force); rb78.AddForce(res78[0], res78[1], res78[2], ForceMode.Force);
        rb79.AddForce(res79[0], res79[1], res79[2], ForceMode.Force); rb80.AddForce(res80[0], res80[1], res80[2], ForceMode.Force); rb81.AddForce(res81[0], res81[1], res81[2], ForceMode.Force);
        rb82.AddForce(res82[0], res82[1], res82[2], ForceMode.Force); rb83.AddForce(res83[0], res83[1], res83[2], ForceMode.Force); rb84.AddForce(res84[0], res84[1], res84[2], ForceMode.Force);
        rb85.AddForce(res85[0], res85[1], res85[2], ForceMode.Force); rb86.AddForce(res86[0], res86[1], res86[2], ForceMode.Force); rb87.AddForce(res87[0], res87[1], res87[2], ForceMode.Force);
        rb88.AddForce(res88[0], res88[1], res88[2], ForceMode.Force); rb89.AddForce(res89[0], res89[1], res89[2], ForceMode.Force); rb90.AddForce(res90[0], res90[1], res90[2], ForceMode.Force);
        rb91.AddForce(res91[0], res91[1], res91[2], ForceMode.Force); rb92.AddForce(res92[0], res92[1], res92[2], ForceMode.Force); rb93.AddForce(res84[0], res93[1], res93[2], ForceMode.Force);
        rb94.AddForce(res94[0], res94[1], res94[2], ForceMode.Force); rb95.AddForce(res95[0], res95[1], res95[2], ForceMode.Force); rb96.AddForce(res87[0], res96[1], res96[2], ForceMode.Force);
        rb97.AddForce(res97[0], res97[1], res97[2], ForceMode.Force); rb98.AddForce(res98[0], res98[1], res98[2], ForceMode.Force); rb99.AddForce(res90[0], res99[1], res99[2], ForceMode.Force);
    }
}

