from setuptools import find_packages
from setuptools import setup

setup(
    name='teb_msgs',
    version='0.0.1',
    packages=find_packages(
        include=('teb_msgs', 'teb_msgs.*')),
)
