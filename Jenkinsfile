pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                git branch: 'main',
                    credentialsId: 'github-token',
                    url: 'https://github.com/stacykins/test_repos.git'
            }
        }

        stage('Restore NuGet Packages') {
            steps {
                echo 'Restoring NuGet packages via nuget.exe...'
                bat '"D:\\nuget.exe" restore test_repos.sln'
            }
        }

        stage('Build') {
            steps {
                bat '"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\MSBuild\\Current\\Bin\\MSBuild.exe" test_repos.sln /p:Configuration=Debug /m'
            }
        }

        stage('Test') {
            steps {
                bat 'x64\\Debug\\test_repos.exe --gtest_output="xml:x64\\Debug\\test_report.xml"'
            }
        }
    }

    post {
        always {
            xunit (
                tools: [
                    [$class: 'GoogleTest', pattern: 'x64/Debug/test_report.xml']
                ]
            )
            archiveArtifacts artifacts: 'x64/Debug/test_report.xml', fingerprint: true
        }
    }
}
