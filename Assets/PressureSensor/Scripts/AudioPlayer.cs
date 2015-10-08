using UnityEngine;
using System.Collections;

public class AudioPlayer : MonoBehaviour {

	int pressureInput;
	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		if(Input.inputString != ""){
			//Debug.Log(Input.inputString);
			pressureInput = int.Parse(Input.inputString);
			Debug.Log (pressureInput);
		}
	}
}
