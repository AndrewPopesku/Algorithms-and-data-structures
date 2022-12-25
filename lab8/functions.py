import xml.etree.ElementTree as ET
import logging

import numpy as np
import scipy as sp
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation


filename = "list.xml"

def generateEmptyListXmlFile(filename):
    #logging.info("Generating empty xml file(" + filename + ")...")
    root = ET.Element("Data")
    init_list = ET.SubElement(root, "InitialList")
    el = ET.SubElement(init_list, "Element")
    el.text = " "
    tree = ET.ElementTree(root)

    with open(filename, "wb") as f:
        tree.write(f)

    #logging.info("Xml file is successfully generated!")

        
def readXmlFile(filename):
    #logging.info("Reading list values from xml file(" + filename + ")...")
    tree = ET.parse(filename)
    root = tree.getroot()

    unsorted_list = []
    for child in root[0]:
        unsorted_list.append(int(child.text))

    #logging.info("List values was successfully read and returned from function!")
    return unsorted_list


def writeXmlFile(arr, filename):
    #logging.info("Writing sorted values from list in xml file back...")
    tree = ET.parse(filename)
    root = tree.getroot()
    if root[1].tag == "SortedList":
        root.remove(root[1])
    list = ET.SubElement(root, "SortedList")
    
    for num in arr:
        el = ET.SubElement(list, "Element")
        el.text = str(num)

    tree = ET.ElementTree(root)
    with open(filename, "wb") as f:
        tree.write(f)

    #logging.info("Sorted list was updated in xml file(" + filename + ").")