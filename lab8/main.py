from visualization import *
from functions import *

def main():
    # logging.basicConfig(level=logging.INFO, filename="lab8/log.log", filemode="w")

    # logging.info("Program is running...")

    u_list = readXmlFile(filename)
    start_visualization(u_list)
    writeXmlFile(u_list, filename)

    # generateEmptyListXmlFile(filename)

    logging.info("Program has finished work.")


if __name__ == "__main__":
    main()