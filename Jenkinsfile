// Имя выходного файла
def EXECUTABLE_FILE_NAME = "send_email"

pipeline {
    agent any
    stages {
        stage('build') {
            steps {
                sh """
                    rm -rf build
                    mkdir build
                    cd build
                    cmake -G "Unix Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release ..
                    cmake --build .
                """
            }
        }

        stage('cppcheck') {
            steps {
                sh 'cppcheck --enable=all --xml --xml-version=2 -i ext  source include 2> build/cppcheck.xml'
                sh 'cppcheck-htmlreport --source-encoding="iso8859-1" --title="project" --source-dir=. --report-dir=build --file=build/cppcheck.xml'
                publishHTML(
                    target: [
                      allowMissing: true,
                      alwaysLinkToLastBuild: false,
                      keepAll: false,
                      reportDir: 'build',
                      reportFiles: 'index.html',
                      reportName: 'CppCheck Report',
                      reportTitles: ''
                    ]
                )
            }
        }

        stage('archive') {
            steps {
                script {
                    sh "zip -r ${EXECUTABLE_FILE_NAME}.zip build/${EXECUTABLE_FILE_NAME}"
                }
            }
        }

        stage('artifacts') {
            steps {
                archiveArtifacts artifacts: "${EXECUTABLE_FILE_NAME}.zip", onlyIfSuccessful: true
            }
        }

        stage('clean') {
            steps {
                cleanWs()
            }
        }
    }

    options {
        buildDiscarder(logRotator(numToKeepStr: '1'))
    }
}
