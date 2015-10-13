using UnityEngine;
using System.Collections;

public class playerMovement : MonoBehaviour {

    public int playerPosition = 0;
    public int leftTreshold = -7000;
    public int rightTreshold = 7000;
    bool atRight = false;
    bool atLeft = false;
    bool positionChanged = false;
    int oldPos = 0;
    float accInput;

    public float turnRotationAngle = 30f;
    private float rotationVelocity;
    public float turnRotationSeekSpeed = .45f;



    void turnRight() {
        Vector3 newRotation = transform.eulerAngles;
        newRotation.z = Mathf.SmoothDampAngle(newRotation.z, 1f * -turnRotationAngle, ref rotationVelocity, turnRotationSeekSpeed);
        transform.eulerAngles = newRotation;
    }

    void turnLeft() {
        Vector3 newRotation = transform.eulerAngles;
        newRotation.z = Mathf.SmoothDampAngle(newRotation.z, -1f * -turnRotationAngle, ref rotationVelocity, turnRotationSeekSpeed);
        transform.eulerAngles = newRotation;
    }

    void backToMiddle() {
        Vector3 newRotation = transform.eulerAngles;
        newRotation.z = Mathf.SmoothDampAngle(newRotation.z, 0f * -turnRotationAngle, ref rotationVelocity, turnRotationSeekSpeed);
        transform.eulerAngles = newRotation;
    }

  
    void Update () {

        //"Fake" rotate the car




        string comingInput = Input.inputString;
        if (Input.inputString != "") {

            if (comingInput[0] == '-') {
                accInput = float.Parse(comingInput.TrimStart('-'));
                accInput = -accInput;
            } else {
                accInput = float.Parse(comingInput);
            }
     
            if (accInput < leftTreshold) {
                Debug.Log("RIGHT");
                atRight = true;
                atLeft = false;
                oldPos = playerPosition;
                playerPosition = 1;
            } else if (accInput > rightTreshold) {
                Debug.Log("LEFT");
                atLeft = true;
                atRight = false;
                oldPos = playerPosition;
                playerPosition = -1;
            } else if (accInput < rightTreshold && accInput > leftTreshold) {
                Debug.Log("MIDDLE");
                atRight = false;
                atLeft = false;
                playerPosition = 0;
            }

        }

        if (atRight) {
            turnRight();
        } else if (atLeft) {
            turnLeft();
        } else {
            backToMiddle();
        }
    }
}
