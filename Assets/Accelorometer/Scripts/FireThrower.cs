using UnityEngine;
using System.Collections;

public class FireThrower : MonoBehaviour {


    public GameObject fireball;
    public float speed = 5f;
    Vector3 ObjectSpawnPosition;
    GameObject fireballInstance;
    

    void fireThrowerStart() {

        fireballInstance = (GameObject)Instantiate(fireball);
        fireballInstance.GetComponent<Rigidbody>().AddForce(new Vector3(0,0,1000f));

        return;
    }

    // Use this for initialization
    void Start () {
        ObjectSpawnPosition.x = transform.position.x; 
        ObjectSpawnPosition.y = transform.position.y;
        ObjectSpawnPosition.z = transform.position.z;


        fireThrowerStart();
    }
	
	// Update is called once per frame
	void Update () {
	
	}
}
