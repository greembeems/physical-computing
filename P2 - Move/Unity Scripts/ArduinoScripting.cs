using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class ArduinoScripting : MonoBehaviour
{
    SerialPort port = new SerialPort("COM3", 9600);
    float force = 0;
    public float Force
    {
        get { return force; }
    }
    

    // Start is called before the first frame update
    void Start()
    {
        port.Open();
        
    }

    // Update is called once per frame
    void Update()
    {
        try
        {
            force = float.Parse(port.ReadLine());
            Debug.Log(force);
        }
        catch
        {
            Debug.Log("No data read");
        }
    }
}
