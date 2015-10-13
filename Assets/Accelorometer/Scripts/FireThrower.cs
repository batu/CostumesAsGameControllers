using UnityEngine;
using System.Collections;

public class FireThrower : MonoBehaviour {


    public GameObject fireball;
    public float speed = 5f;
    public float moveAmount = 5;
    public float fireballFrequency = 3;
    Vector3 ObjectSpawnPosition;
    GameObject fireballInstance;
    

    void fireThrowerStart() {

        int random = Random.Range(0, 3);
        if (random == 0) {
            fireballInstance = (GameObject)Instantiate(fireball,ObjectSpawnPosition,Quaternion.identity);
        } else if( random == 1) {
            fireballInstance = (GameObject)Instantiate(fireball, ObjectSpawnPosition + new Vector3(moveAmount, 0,0), Quaternion.identity);
        }else if(random == 2) { 
            fireballInstance = (GameObject)Instantiate(fireball, ObjectSpawnPosition + new Vector3(-moveAmount, 0, 0), Quaternion.identity);
        }


        Debug.Log(fireballInstance.name);
        return;
    }

    // Use this for initialization
    void Start () {
        ObjectSpawnPosition.x = transform.position.x; 
        ObjectSpawnPosition.y = transform.position.y;
        ObjectSpawnPosition.z = transform.position.z;

        InvokeRepeating("fireThrowerStart", 2, fireballFrequency);

    }
	
	// Update is called once per frame
	void Update () {

        
    }
}
