import xml.etree.ElementTree as ET

def hanoiTower(n, from_rod, to_rod, extra_rod):
    if (n == 0):
        return
    
    hanoiTower(n - 1, from_rod, extra_rod, to_rod)
    addStepToXmlOutput(n, from_rod, to_rod)
    hanoiTower(n - 1, extra_rod, to_rod, from_rod)


def addStepToXmlOutput(num_disk, _from, _to):
    step = ET.SubElement(steps, "Step")
    disk = ET.SubElement(step, "Disk")
    disk.text = str(num_disk)

    from_rod = ET.SubElement(step, "From")
    from_rod.text = _from

    to_rod = ET.SubElement(step, "To")
    to_rod.text = _to

    
n = int(input("Enter number of disks in first rod: "))

data = ET.Element("HanoiTower")
data.set("NumberOfDisks", str(n))
steps = ET.SubElement(data, "Steps")

hanoiTower(n, 'A', 'B', 'C')

b_xml = ET.tostring(data)
with open("output.xml", "wb") as f:
    f.write(b_xml)

print("Xml file written succesfully!")