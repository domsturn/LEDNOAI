pipeline {
	agent none

	stages {
		stage('Checkout'){
		agent {label 'docker-arm'}
			steps{
				checkout scm
				echo 'git checkout complete'
			}
		}
		stage('Build Firmware'){
		agent {'docker-arm'}
			steps{
				sh 'make'
				echo 'firmware build completet'
			}
		}
		stage('Flash Arduino'){
		agent {'flash-node'}
			steps{
				sh'''
				chmod +x scripts/flashskript.sh
				./scripts/flashskript.sh
				'''
			echo 'Flash completet'
			}
		}
	}
}