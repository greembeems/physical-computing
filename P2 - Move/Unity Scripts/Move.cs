using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Move : MonoBehaviour
{
    [SerializeField]
    ArduinoScripting duino;

    [SerializeField]
    Vector3 oPosition;

    [SerializeField]
    Vector3 maxPos = new Vector3(100, 0, 0);

    Vector3 nPos = new Vector3(100, 0, 0);

    Vector3 speed = Vector3.zero;

    // Start is called before the first frame update
    void Start()
    {
        oPosition = gameObject.transform.position;
    }

    // Update is called once per frame
    void Update()
    {
        if (duino.Force >= 100)
        {
            speed.x = duino.Force / 100;
            nPos = maxPos;
        }
        else
        {
            nPos = oPosition;
            speed.x = -speed.x;
        }

        if (gameObject.transform.position.x < maxPos.x)
        {
            gameObject.transform.position = gameObject.transform.position + speed * Time.deltaTime;
        }
    }
}
