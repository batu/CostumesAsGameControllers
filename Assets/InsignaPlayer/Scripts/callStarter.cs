using UnityEngine;
using System.Collections;

public class callStarter : MonoBehaviour {

    public AudioClip phoneSound;


	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	    if ( !GetComponent<AudioSource>().isPlaying && Input.GetMouseButtonDown(0)) {
            Debug.Log("Input");
            GetComponent<AudioSource>().PlayOneShot(phoneSound);
        }
        
	}
}
