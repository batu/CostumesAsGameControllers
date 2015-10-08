using UnityEngine;
using System.Collections;

public class Player : MonoBehaviour {

	public GameObject playerObj, targetObj, indicator;
	int pressureInput;
	float initPosition;
	float offset;
	Vector3 offsetPosition;
	float speed = 5.0f;
	int counter = 0;
	// Use this for initialization
	void Start () {
		initPosition = playerObj.transform.position.x;
	}



	// Update is called once per frame
	void Update () {
		if(Input.inputString != ""){
			//Debug.Log(Input.inputString);
			pressureInput = int.Parse(Input.inputString);

			offset = pressureInput / 100f;
			offsetPosition = new Vector3(offset,0,0);
			Debug.Log (offset);
			targetObj.transform.position = new Vector3 ( initPosition + offset
			                                            ,playerObj.transform.position.y
			                                            ,playerObj.transform.position.z);
			counter = 0;
		}
		
		if(Input.inputString == ""){
			counter++;
			Debug.Log(counter);
			if(counter == 30){
				Debug.Log("I am in counter!");
				targetObj.transform.position = new Vector3 ( initPosition 
				                                            ,playerObj.transform.position.y
				                                            ,playerObj.transform.position.z);
			}

		}
		
			playerObj.transform.position = Vector3.Lerp(playerObj.transform.position, targetObj.transform.position, Time.deltaTime * speed);
			

		
	}
}
