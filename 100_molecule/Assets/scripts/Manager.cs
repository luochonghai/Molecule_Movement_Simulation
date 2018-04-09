using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Manager: MonoBehaviour {
    public int size=10;
    public int range = 30;
    public GameObject module;
    private GameObject[] bows;
	// Use this for initialization
	void Start () {
        bows = new GameObject[size];
        for(int i = 0; i < size; i++)
        {
            Vector3 r = new Vector3(Random.Range(0, range), Random.Range(0, range), Random.Range(0, range));
            bows[i] = Instantiate(module, transform.position+r, transform.rotation);
            bows[i].GetComponent<Bow>().SetManager(this);
        }
	}
	public GameObject[] getBows()
    {
        return bows;
    }
	// Update is called once per frame
	void Update () {
		
	}
}
