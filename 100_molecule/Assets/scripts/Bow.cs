using System.Collections;
using System.Collections.Generic;
using System.IO;
using System;
using UnityEngine;

public class Bow : MonoBehaviour {
    private Manager manager;
    public float force_b = 3000f;
    public float mul_k = 5;
    private Rigidbody rigidbody;
    // Use this for initialization
    void Start () {
        rigidbody = GetComponent<Rigidbody>(); 
	}

    Vector3 Force_cal(Vector3 player_position, Vector3 sphere1_position)
    {
        float delta_x = player_position.x - sphere1_position.x;
        float delta_y = player_position.y - sphere1_position.y;
        float delta_z = player_position.z - sphere1_position.z;
        double dist = delta_x * delta_x + delta_y * delta_y + delta_z * delta_z;
        float distance = float.Parse((Math.Sqrt(dist)).ToString());
        float Force_2 = mul_k / distance / distance / distance - 1 / distance / distance;
        Force_2 *= force_b;
        Vector3 res = new Vector3();
        res.x = delta_x * Force_2 / distance;
        res.y = delta_y * Force_2 / distance;
        res.z = delta_z * Force_2 / distance;
        return res;
    }

    // Update is called once per frame
    void Update () {
        if (manager != null)
        {
            GameObject[] bows = manager.getBows();
            //FileStream fs = new FileStream("coordinate.txt", FileMode.Append);
            //StreamWriter sw = new StreamWriter(fs);
            for (int i = 0; i < bows.Length; i++)
            {
                string coordi = "bowl "+(i%(bows.Length)).ToString()+"(x:"+bows[i].transform.position.x.ToString()+",";
                coordi += "y:" + bows[i].transform.position.y.ToString() + ",";
                coordi += "z:" + bows[i].transform.position.z.ToString() + ")";

                //sw.WriteLine(coordi);

                //if (bows[i].transform.position != gameObject.transform.position)
                if (bows[i] != gameObject)
                {
                    rigidbody.AddForce(Force_cal(transform.position,bows[i].transform.position),ForceMode.Force);
                }
            }
            //sw.Close();
            //fs.Close();
        }
    }
    public void SetManager(Manager m)
    {
        manager = m;
    }
}
